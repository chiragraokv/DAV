module full_adder(a, b, c, sum, carry);
    input a, b, c;
    output sum, carry;

    wire ab, bc, ac, temp_sum;

    // Sum = (a ⊕ b) ⊕ c
    xor x1(temp_sum, a, b);
    xor x2(sum, temp_sum, c);

    // Carry = (a & b) | (b & c) | (a & c)
    and a1(ab, a, b);
    and a2(bc, b, c);
    and a3(ac, a, c);
    or  o1(carry, ab, bc, ac);

endmodule
