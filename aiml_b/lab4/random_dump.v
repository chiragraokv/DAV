// Full Adder Module
module full_adder(a, b, cin, sum, cout);
    input a, b, cin;
    output sum, cout;
    
    // Sum = a XOR b XOR cin
    assign sum = a ^ b ^ cin;
    
    // Carry out = ab + cin(a XOR b) = ab + cin*a + cin*b
    assign cout = (a & b) | (cin & (a ^ b));
endmodule

// Your 4-bit Adder Module
module four_bit(a, b, cin, sum, cout);
    input [3:0] a, b;
    input cin;
    output [3:0] sum;
    output cout;

    wire c1, c2, c3;

    full_adder fa0(a[0], b[0], cin,   sum[0], c1);
    full_adder fa1(a[1], b[1], c1,    sum[1], c2);
    full_adder fa2(a[2], b[2], c2,    sum[2], c3);
    full_adder fa3(a[3], b[3], c3,    sum[3], cout);
endmodule

// Alternative Full Adder using gate-level modeling
module full_adder_gates(a, b, cin, sum, cout);
    input a, b, cin;
    output sum, cout;
    
    wire ab, a_xor_b, cin_and_axorb;
    
    // Sum logic
    xor gate1(a_xor_b, a, b);
    xor gate2(sum, a_xor_b, cin);
    
    // Carry logic  
    and gate3(ab, a, b);
    and gate4(cin_and_axorb, cin, a_xor_b);
    or  gate5(cout, ab, cin_and_axorb);
endmodule

// BCD Filter using your 4-bit adder
module bcd_filter_with_four_bit(binary_in, bcd_out, correction_applied);
    input [3:0] binary_in;
    output [3:0] bcd_out;
    output correction_applied;
    
    wire [3:0] add_six_result;
    wire add_six_carry;
    wire [3:0] final_result;
    wire final_carry;
    
    // First adder: Add 6 to check for overflow
    four_bit adder1(
        .a(binary_in),
        .b(4'b0110),        // Add 6
        .cin(1'b0),
        .sum(add_six_result),
        .cout(add_six_carry)
    );
    
    // Determine if correction is needed
    // Method 1: Check carry out (input >= 10 will cause carry when adding 6)
    // Method 2: Check bit patterns for inputs > 9
    wire needs_correction_carry = add_six_carry;
    wire needs_correction_pattern = (binary_in[3] & binary_in[2]) | (binary_in[3] & binary_in[1]);
    
    assign correction_applied = needs_correction_carry | needs_correction_pattern;
    
    // Second adder: Apply correction if needed
    wire [3:0] correction_value = correction_applied ? 4'b0110 : 4'b0000;
    
    four_bit adder2(
        .a(binary_in),
        .b(correction_value),
        .cin(1'b0),
        .sum(final_result),
        .cout(final_carry)
    );
    
    assign bcd_out = final_result;
endmodule

// Comprehensive testbench
module tb_four_bit;
    
    reg [3:0] a, b;
    reg cin;
    wire [3:0] sum;
    wire cout;
    
    // Instantiate the 4-bit adder
    four_bit uut(
        .a(a),
        .b(b), 
        .cin(cin),
        .sum(sum),
        .cout(cout)
    );
    
    // Test BCD filter
    reg [3:0] bcd_input;
    wire [3:0] bcd_output;
    wire bcd_corrected;
    
    bcd_filter_with_four_bit bcd_uut(
        .binary_in(bcd_input),
        .bcd_out(bcd_output),
        .correction_applied(bcd_corrected)
    );
    
    initial begin
        $display("4-bit Ripple Carry Adder Test");
        $display("=============================");
        $display("A    B    Cin | Sum  Cout | Expected | Status");
        $display("-------------|-----------|----------|-------");
        
        // Test basic addition
        a = 4'b0011; b = 4'b0101; cin = 1'b0; #10;
        check_result("Basic Add");
        
        // Test with carry in
        a = 4'b0111; b = 4'b1000; cin = 1'b1; #10;
        check_result("With Cin");
        
        // Test maximum addition
        a = 4'b1111; b = 4'b1111; cin = 1'b1; #10;
        check_result("Maximum");
        
        // Test zero
        a = 4'b0000; b = 4'b0000; cin = 1'b0; #10;
        check_result("Zero");
        
        // Test carry propagation
        a = 4'b0001; b = 4'b1111; cin = 1'b0; #10;
        check_result("Carry Prop");
        
        // Test BCD relevant cases
        a = 4'b1001; b = 4'b0110; cin = 1'b0; #10;  // 9 + 6
        check_result("BCD: 9+6");
        
        a = 4'b1010; b = 4'b0110; cin = 1'b0; #10;  // 10 + 6  
        check_result("BCD: 10+6");
        
        $display("\nBCD Filter Test using 4-bit Adder");
        $display("==================================");
        $display("Input | Binary | BCD Out | Corrected | Expected");
        $display("------|--------|---------|-----------|----------");
        
        // Test BCD filter
        for (integer i = 0; i < 16; i = i + 1) begin
            bcd_input = i;
            #10;
            $display("%2d    | %b  | %b   |    %b      | %s",
                    i, bcd_input, bcd_output, bcd_corrected,
                    (i <= 9) ? "Pass through" : "Correct to BCD");
        end
        
        $display("\nDetailed Analysis:");
        bcd_input = 4'b1010; #10;  // 10
        $display("Input 10 (1010): Output = %b (%d), Corrected = %b", 
                bcd_output, bcd_output, bcd_corrected);
        
        bcd_input = 4'b1111; #10;  // 15
        $display("Input 15 (1111): Output = %b (%d), Corrected = %b", 
                bcd_output, bcd_output, bcd_corrected);
        
        // Verify carry chain timing
        $display("\nCarry Propagation Test:");
        test_carry_timing();
        
        $finish;
    end
    
    // Task to check addition results
    task check_result(input [63:0] test_name);
        reg [4:0] expected;
        begin
            expected = a + b + cin;
            $display("%b %b  %b  | %b %b  | %b%b    | %s %s",
                    a, b, cin, sum, cout, expected[4], expected[3:0], test_name,
                    ({cout, sum} == expected) ? "✓" : "✗");
        end
    endtask
    
    // Test carry propagation timing
    task test_carry_timing();
        begin
            $display("Testing worst-case carry propagation (0001 + 1111):");
            a = 4'b0001; b = 4'b1111; cin = 1'b0;
            
            // Monitor intermediate carries
            $display("Input: A=%b, B=%b", a, b);
            #1;  // Allow combinational delay
            $display("Carries: c1=%b, c2=%b, c3=%b, cout=%b", 
                    uut.c1, uut.c2, uut.c3, cout);
            $display("Result: %b%b (expected: 10000)", cout, sum);
        end
    endtask
    
    // Monitor all signals for debugging
    initial begin
        $monitor("Time=%0t: a=%b, b=%b, cin=%b -> sum=%b, cout=%b", 
                $time, a, b, cin, sum, cout);
    end
    
endmodule

// Test individual full adder
module tb_full_adder;
    
    reg a, b, cin;
    wire sum, cout;
    
    full_adder fa_test(.a(a), .b(b), .cin(cin), .sum(sum), .cout(cout));
    
    initial begin
        $display("\nFull Adder Truth Table:");
        $display("A B Cin | Sum Cout");
        $display("--------|----------");
        
        // Test all 8 combinations
        for (integer i = 0; i < 8; i = i + 1) begin
            {a, b, cin} = i;
            #10;
            $display("%b %b  %b  |  %b   %b", a, b, cin, sum, cout);
        end
    end
    
endmodule

// Performance comparison module
module performance_comparison;
    
    reg [3:0] a, b;
    reg cin;
    wire [3:0] sum_ripple, sum_direct;
    wire cout_ripple, cout_direct;
    
    // Your ripple carry implementation
    four_bit ripple_adder(.a(a), .b(b), .cin(cin), .sum(sum_ripple), .cout(cout_ripple));
    
    // Direct implementation for comparison
    wire [4:0] direct_result = a + b + cin;
    assign sum_direct = direct_result[3:0];
    assign cout_direct = direct_result[4];
    
    initial begin
        $display("\nPerformance Comparison:");
        $display("Ripple Carry vs Direct Addition");
        $display("===============================");
        
        // Test several cases
        for (integer i = 0; i < 5; i = i + 1) begin
            a = $random % 16;
            b = $random % 16; 
            cin = $random % 2;
            #10;
            
            $display("A=%b, B=%b, Cin=%b", a, b, cin);
            $display("Ripple: %b%b, Direct: %b%b, Match: %s", 
                    cout_ripple, sum_ripple, cout_direct, sum_direct,
                    ({cout_ripple, sum_ripple} == {cout_direct, sum_direct}) ? "✓" : "✗");
        end
    end
    
endmodule