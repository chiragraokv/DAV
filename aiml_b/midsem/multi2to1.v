    module multi2to1 (
        input s,w1,w0,
        output out
    );

    wire nots,a1,a0;

    not(nots,s);
    and(a1,w1,s);
    and(a0,w0,nots);

    or(out,a0,a1);

    endmodule