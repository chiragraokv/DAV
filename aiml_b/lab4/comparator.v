module comparator(
    input  [3:0] a, b,
    output reg lt, gt, eq
);
    always @(*) begin
        if (a < b) begin
            lt = 1; gt = 0; eq = 0;
        end else if (a > b) begin
            lt = 0; gt = 1; eq = 0;
        end else begin
            lt = 0; gt = 0; eq = 1;
        end
    end
endmodule
