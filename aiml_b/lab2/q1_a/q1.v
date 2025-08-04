module q1(a, b, c, d, f);
    input a, b, c, d;
    output f;
    assign f = ((~a & b) | (b & ~c & ~d) | (~b & c) | (c & d));
    
endmodule
