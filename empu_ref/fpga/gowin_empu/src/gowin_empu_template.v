
//sys_clk max 80MHz
//GPIO
//UART0
//Timer0/1
//WatchDog
//RTC
//APB2 Master [1] for a APB multiplier
//AHB2 Master for a AHB multiplier

`resetall

module Gowin_EMPU_Template (
  sys_clk,
  reset_n,
  gpioin,
  gpioout,
  uart0_rxd,
  uart0_txd
);

input sys_clk;
input reset_n;

//GPIO
input gpioin;
output gpioout;

//UART0
input uart0_rxd;
output uart0_txd;

/*------------------------- APB2 Master [1] --------------------------*/
wire        master_pclk;
wire        master_rst;
wire        master_penable;
wire [7:0]  master_paddr;
wire        master_pwrite;
wire [31:0] master_pwdata;
wire [3:0]  master_pstrb;
wire [2:0]  master_pprot;
wire        master_psel1;
wire [31:0] master_prdata1;
wire        master_pready1;
wire        psel_valid_es1;
wire        penable_valid_es1;

Gowin_APB2_Multiple multiple_template (
 .pclk(master_pclk), 
 .presetn(master_rst),
 .psel(psel_valid_es1), 
 .penable(penable_valid_es1),
 .pwrite(master_pwrite), 
 .paddr({4'b0000,master_paddr[7:2]}),  
 .pwdata(master_pwdata), 
 .prdata(master_prdata1)
);

Gowin_APB2_Decoder 
    #(.ADDR_WIDTH(8))
 u_multiple_1(
     .paddr_i        ({24'h0,master_paddr[7:0]}),
	 .penable_i      (master_penable           ),
	 .pprot_i        (master_pprot[0]          ),
	 .secure_i       (1'b0                     ),
	 .pready_i       (1'b1                     ),
	 .psel_valid_o   (psel_valid_es1           ),//decoded psel to slave
     .penable_valid_o(penable_valid_es1        ),//decoded penable to slave
     .pready_o       (master_pready1           ),
     .psel_i         (master_psel1             )
  );
/*------------------------- APB2 Master [1] --------------------------*/

/*------------------------- AHB2 Master --------------------------*/
wire master_hclk ;
wire master_hrst ;
wire master_hsel ;
wire [31:0] master_haddr ;
wire [1:0] master_htrans ;
wire master_hwrite ;
wire [2:0] master_hsize ;
wire [2:0] master_hburst ;
wire [3:0] master_hprot ;
wire [1:0] master_memattr ;//
wire master_exreq ;//
wire [3:0] master_hmaster ;
wire [31:0] master_hwdata ;
wire master_hmastlock ;
wire master_hreadymux ;
wire master_hauser ;//
wire [3:0] master_hwuser ;//
wire [31:0] master_hrdata ;
wire master_hreadyout ;
wire master_hresp ;

Gowin_AHB_Multiple u_ahb_multiple
(
	.AHB_HRDATA(master_hrdata),
	.AHB_HREADY(master_hreadyout),//ready signal, slave to MCU master, 1'b1
	.AHB_HRESP(master_hresp),//respone signal, slave to MCU master
	.AHB_HTRANS(master_htrans),
	.AHB_HBURST(master_hburst),
	.AHB_HPROT(master_hprot),
	.AHB_HSIZE(master_hsize),
	.AHB_HWRITE(master_hwrite),
	.AHB_HMASTLOCK(master_hmastlock),
	.AHB_HMASTER(master_hmaster),
	.AHB_HADDR(master_haddr[11:0]),
	.AHB_HWDATA(master_hwdata),
	.AHB_HSEL(master_hsel),
	.AHB_HCLK(master_hclk),
	.AHB_HRESETn(master_hrst)
);
/*------------------------- AHB2 Master --------------------------*/

/*--------------------Gowin_EMPU_Top---------------------------*/
wire mclk;              //mcu clock
wire rtc_src_clk;       //rtc clock
wire clkin = sys_clk;
wire [14:0] gpioout_o;
wire [15:0] gpioouten_o;

//MCU system clock = 80MHz
//Gowin_PLLVR u_Gowin_PLLVR(
//  .clkout(mclk),            //MCU 80MHz
//  .clkoutd(rtc_src_clk),    //RTC 3.072MHz
//  .clkin(clkin)             //input clkin 50MHz
//);

//MCU system clock = 81MHz
 EMCU_PLLVR u_Gowin_PLLVR(
        .clkout(mclk), //output clkout MCU - 81.0 MHz
        .clkoutd(rtc_src_clk), //output clkoutd RTC- 3.115 MHz tolerance 0.2
        .clkin(clkin) //input clkin - 27 MHz
 );

Gowin_EMPU_Top u_Gowin_EMPU_Top (
  .sys_clk(mclk),
  .reset_n(reset_n),
  //RTC
  .rtc_src_clk(rtc_src_clk),
  //GPIO
  .gpioin({14'b00_0000_0000_0000,gpioin,1'b0}),
  .gpioout({gpioout_o,gpioout}),
  .gpioouten(gpioouten_o),
  //UART0
  .uart0_rxd(uart0_rxd),
  .uart0_txd(uart0_txd),
  //----APB2 Master [1]----//
  .master_pclk(master_pclk),
  .master_rst(master_rst),
  .master_penable(master_penable),
  .master_paddr(master_paddr),
  .master_pwrite(master_pwrite),
  .master_pwdata(master_pwdata),
  .master_pstrb(master_pstrb),
  .master_pprot(master_pprot),
  .master_psel1(master_psel1),
  .master_prdata1(master_prdata1),
  .master_pready1(master_pready1),
  .master_pslverr1(1'b0),
  //----AHB2 Master----//
  .master_hclk(master_hclk),
  .master_hrst(master_hrst),
  .master_hsel(master_hsel),
  .master_haddr(master_haddr),
  .master_htrans(master_htrans),
  .master_hwrite(master_hwrite),
  .master_hsize(master_hsize),
  .master_hburst(master_hburst),
  .master_hprot(master_hprot),
  .master_memattr(master_memattr),
  .master_exreq(master_exreq),
  .master_hmaster(master_hmaster),
  .master_hwdata(master_hwdata),
  .master_hmastlock(master_hmastlock),
  .master_hreadymux(master_hreadymux),
  .master_hauser(master_hauser),
  .master_hwuser(master_hwuser),
  .master_hrdata(master_hrdata),
  .master_hreadyout(master_hreadyout),
  .master_hresp(master_hresp),
  .master_exresp(1'b0),
  .master_hruser(3'b000)
);

endmodule