module bcd_boolean_analysis (
    input [3:0] binary_in,
    output need_correction,
    output method1_result,
    output method2_result,
    output method3_result
);

// Let's name the input bits for clarity
wire b3, b2, b1, b0;
assign {b3, b2, b1, b0} = binary_in;

// METHOD 1: Direct Boolean Expression
// Need correction when input > 9 (i.e., input >= 10)
// This happens for: 10, 11, 12, 13, 14, 15
// In binary: 1010, 1011, 1100, 1101, 1110, 1111

assign method1_result = (b3 & b2) |     // Covers: 1100, 1101, 1110, 1111 (12,13,14,15)
                       (b3 & b1);       // Covers: 1010, 1011, 1110, 1111 (10,11,14,15)

// METHOD 2: Using Karnaugh Map Simplification
// Truth table analysis:
// 0000(0)→0, 0001(1)→0, 0010(2)→0, 0011(3)→0
// 0100(4)→0, 0101(5)→0, 0110(6)→0, 0111(7)→0  
// 1000(8)→0, 1001(9)→0, 1010(10)→1, 1011(11)→1
// 1100(12)→1, 1101(13)→1, 1110(14)→1, 1111(15)→1

assign method2_result = b3 & (b2 | b1);  // Simplified K-map result

// METHOD 3: Using addition overflow detection
// If we add 6 to input and get carry out, then input was >= 10
wire [4:0] add_six_result;
assign add_six_result = binary_in + 4'b0110;
assign method3_result = add_six_result[4];  // Carry out bit

// All methods should give same result
assign need_correction = method1_result;

endmodule
