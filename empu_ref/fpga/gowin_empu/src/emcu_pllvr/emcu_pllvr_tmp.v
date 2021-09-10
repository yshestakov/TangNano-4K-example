//Copyright (C)2014-2021 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: V1.9.8
//Part Number: GW1NSR-LV4CQN48PC7/I6
//Device: GW1NSR-4C
//Created Time: Thu Sep 09 00:15:30 2021

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

    EMCU_PLLVR uEMCU_PLLVR(
        .clkout(clkout_o), //output clkout - 81.0 MHz
        .clkoutd(clkoutd_o), //output clkoutd - 3.115 MHz tolerance 0.2
        .clkin(clkin_i) //input clkin - 27 MHz
    );

//--------Copy end-------------------
