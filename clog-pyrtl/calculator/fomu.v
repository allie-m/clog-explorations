// Simple tri-colour LED blink example.

// Correctly map pins for the iCE40UP5K SB_RGBA_DRV hard macro.

`define GREENPWM RGB0PWM
`define REDPWM   RGB1PWM
`define BLUEPWM  RGB2PWM

// taken (mostly) from
// https://github.com/im-tomu/fomu-workshop/blob/master/hdl/verilog/blink-expanded/blink.v

module top (
    // 48MHz Clock input
    // --------
    input clki,
    // LED outputs
    // --------
    output rgb0,
    output rgb1,
    output rgb2,
    // User touchable pins
    // --------
    // Connect 1-2 to enable blue LED
    input  user_1,
    output user_2,
    // Connect 3-4 to enable red LED
    output user_3,
    input  user_4,
    // USB Pins (which should be statically driven if not being used).
    // --------
    output usb_dp,
    output usb_dn,
    output usb_dp_pu
);

    // Assign USB pins to "0" so as to disconnect Fomu from
    // the host system.  Otherwise it would try to talk to
    // us over USB, which wouldn't work since we have no stack.
    assign usb_dp = 1'b0;
    assign usb_dn = 1'b0;
    assign usb_dp_pu = 1'b0;
    // Configure user pins so that we can detect the user connecting
    // 1-2 or 3-4 with conductive material.
    //
    // We do this by grounding user_2 and user_3, and configuring inputs
    // with pullups on user_1 and user_4.
    assign user_2 = 1'b0;
    assign user_3 = 1'b0;

    // Connect to system clock (with buffering)
    wire clk;
    SB_GB clk_gb (
        .USER_SIGNAL_TO_GLOBAL_BUFFER(clki),
        .GLOBAL_BUFFER_OUTPUT(clk)
    );

    // PyRTL module goes here:
    wire [3:0] colors;
    toplevel pyrtl_toplevel (
        .clk (clk),
        .in_1 (~user_1),
        .in_2 (~user_4),
        .red_o (colors[0]),
        .green_o (colors[1]),
        .blue_o (colors[2])
    );

    // Instantiate iCE40 LED driver hard logic, connecting up
    // counter state and LEDs.
    //
    // Note that it's possible to drive the LEDs directly,
    // however that is not current-limited and results in
    // overvolting the red LED.
    //
    // See also:
    // https://www.latticesemi.com/-/media/LatticeSemi/Documents/ApplicationNotes/IK/ICE40LEDDriverUsageGuide.ashx?document_id=50668
    SB_RGBA_DRV #(
        .CURRENT_MODE("0b1"),       // half current
        .RGB0_CURRENT("0b000011"),  // 4 mA
        .RGB1_CURRENT("0b000011"),  // 4 mA
        .RGB2_CURRENT("0b000011")   // 4 mA
    ) RGBA_DRIVER (
        .CURREN(1'b1),
        .RGBLEDEN(1'b1),
        .`REDPWM(colors[0]),      // Red
        .`GREENPWM(colors[1]),    // Green
        .`BLUEPWM(colors[2]),     // Blue
        .RGB0(rgb0),
        .RGB1(rgb1),
        .RGB2(rgb2)
    );

endmodule
