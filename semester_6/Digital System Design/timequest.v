module add_three_numbers(clock, A, B, C, sum);
    input clock;
    input [7:0] A,B,C;
    output [9:0] sum;
    // Registers
    reg [7:0] reg_A, reg_B, reg_C /* synthesis keep */;
    reg [9:0] reg_sum /* synthesis keep */;
    always @(posedge clock)
    begin
    reg_A <= A;
    reg_B <= B;
    reg_C <= C;
    reg_sum <= reg_A + reg_B + reg_C;
    end
    assign sum = reg_sum;
endmodule