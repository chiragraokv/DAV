module q3(a, b, c, d, f);
    input a, b, c, d;
    output f;
    assign f = (~(a)|d)&(a|(~c)|d);
    
endmodule
