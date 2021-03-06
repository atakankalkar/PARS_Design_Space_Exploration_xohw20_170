// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module mod_r (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        x,
        ap_return
);

parameter    ap_ST_fsm_state1 = 4'd1;
parameter    ap_ST_fsm_state2 = 4'd2;
parameter    ap_ST_fsm_state3 = 4'd4;
parameter    ap_ST_fsm_state4 = 4'd8;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [31:0] x;
output  [14:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;

(* fsm_encoding = "none" *) reg   [3:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [31:0] lowbits_r_fu_48_p1;
reg   [31:0] lowbits_r_reg_173;
wire    ap_CS_fsm_state2;
reg   [31:0] lowbits_l_reg_178;
wire   [44:0] pp2_fu_74_p2;
reg   [44:0] pp2_reg_183;
wire    ap_CS_fsm_state3;
reg   [12:0] tmp_6_reg_188;
wire   [52:0] grp_fu_42_p0;
wire   [63:0] grp_fu_42_p2;
wire   [31:0] pp1_fu_65_p1;
wire   [31:0] pp2_fu_74_p1;
wire   [44:0] pp1_fu_65_p2;
wire    ap_CS_fsm_state4;
wire   [44:0] pp1_1_cast_fu_90_p1;
wire   [44:0] pp2_1_fu_93_p2;
wire   [12:0] tmp_7_fu_98_p4;
wire   [0:0] tmp_2_fu_112_p3;
wire   [13:0] ret3_cast_fu_108_p1;
wire   [13:0] tmp_28_cast_cast_fu_119_p3;
wire   [13:0] ret3_fu_127_p2;
wire   [13:0] tmp_4_fu_145_p2;
wire   [0:0] tmp_3_fu_133_p3;
wire   [14:0] tmp_4_cast_fu_151_p1;
wire  signed [14:0] tmp_3_cast_fu_141_p1;
reg   [3:0] ap_NS_fsm;
wire   [44:0] pp1_fu_65_p10;
wire   [44:0] pp2_fu_74_p10;

// power-on initialization
initial begin
#0 ap_CS_fsm = 4'd1;
end

RLWE_enc2_mul_53nfYi #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 53 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
RLWE_enc2_mul_53nfYi_U12(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_42_p0),
    .din1(x),
    .ce(1'b1),
    .dout(grp_fu_42_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        lowbits_l_reg_178 <= {{grp_fu_42_p2[63:32]}};
        lowbits_r_reg_173 <= lowbits_r_fu_48_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        pp2_reg_183 <= pp2_fu_74_p2;
        tmp_6_reg_188 <= {{pp1_fu_65_p2[44:32]}};
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | ((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1)))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_return = ((tmp_3_fu_133_p3[0:0] === 1'b1) ? tmp_4_cast_fu_151_p1 : tmp_3_cast_fu_141_p1);

assign grp_fu_42_p0 = 64'd2401607092007494;

assign lowbits_r_fu_48_p1 = grp_fu_42_p2[31:0];

assign pp1_1_cast_fu_90_p1 = tmp_6_reg_188;

assign pp1_fu_65_p1 = pp1_fu_65_p10;

assign pp1_fu_65_p10 = lowbits_r_reg_173;

assign pp1_fu_65_p2 = (45'd7681 * pp1_fu_65_p1);

assign pp2_1_fu_93_p2 = (pp1_1_cast_fu_90_p1 + pp2_reg_183);

assign pp2_fu_74_p1 = pp2_fu_74_p10;

assign pp2_fu_74_p10 = lowbits_l_reg_178;

assign pp2_fu_74_p2 = (45'd7681 * pp2_fu_74_p1);

assign ret3_cast_fu_108_p1 = tmp_7_fu_98_p4;

assign ret3_fu_127_p2 = (ret3_cast_fu_108_p1 - tmp_28_cast_cast_fu_119_p3);

assign tmp_28_cast_cast_fu_119_p3 = ((tmp_2_fu_112_p3[0:0] === 1'b1) ? 14'd7680 : 14'd0);

assign tmp_2_fu_112_p3 = x[32'd31];

assign tmp_3_cast_fu_141_p1 = $signed(ret3_fu_127_p2);

assign tmp_3_fu_133_p3 = ret3_fu_127_p2[32'd13];

assign tmp_4_cast_fu_151_p1 = tmp_4_fu_145_p2;

assign tmp_4_fu_145_p2 = (14'd7681 + ret3_fu_127_p2);

assign tmp_7_fu_98_p4 = {{pp2_1_fu_93_p2[44:32]}};

endmodule //mod_r
