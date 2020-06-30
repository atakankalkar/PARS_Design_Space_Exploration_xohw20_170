-- ==============================================================
-- File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2017.4
-- Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
-- 
-- ==============================================================

library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity knuth_yao_single_Ngs_rom is 
    generic(
             dwidth     : integer := 1; 
             awidth     : integer := 7; 
             mem_size    : integer := 109
    ); 
    port (
          addr0      : in std_logic_vector(awidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(dwidth-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of knuth_yao_single_Ngs_rom is 

signal addr0_tmp : std_logic_vector(awidth-1 downto 0); 
type mem_array is array (0 to mem_size-1) of std_logic_vector (dwidth-1 downto 0); 
signal mem : mem_array := (
    0 to 12=> "0", 13 => "1", 14 to 18=> "0", 19 to 21=> "1", 22 to 24=> "0", 25 => "1", 26 => "0", 
    27 to 28=> "1", 29 => "0", 30 to 32=> "1", 33 => "0", 34 to 37=> "1", 38 => "0", 39 => "1", 
    40 => "0", 41 => "1", 42 => "0", 43 to 44=> "1", 45 to 47=> "0", 48 => "1", 49 => "0", 
    50 => "1", 51 to 53=> "0", 54 to 55=> "1", 56 => "0", 57 to 59=> "1", 60 to 63=> "0", 64 => "1", 
    65 to 66=> "0", 67 to 69=> "1", 70 to 71=> "0", 72 to 73=> "1", 74 to 75=> "0", 76 => "1", 77 to 78=> "0", 
    79 => "1", 80 to 82=> "0", 83 => "1", 84 => "0", 85 => "1", 86 to 87=> "0", 88 => "1", 
    89 to 90=> "0", 91 to 92=> "1", 93 => "0", 94 => "1", 95 => "0", 96 to 98=> "1", 99 => "0", 
    100 => "1", 101 => "0", 102 => "1", 103 to 104=> "0", 105 to 107=> "1", 108 => "0" );

attribute syn_rom_style : string;
attribute syn_rom_style of mem : signal is "select_rom";
attribute ROM_STYLE : string;
attribute ROM_STYLE of mem : signal is "distributed";

begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;


Library IEEE;
use IEEE.std_logic_1164.all;

entity knuth_yao_single_Ngs is
    generic (
        DataWidth : INTEGER := 1;
        AddressRange : INTEGER := 109;
        AddressWidth : INTEGER := 7);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of knuth_yao_single_Ngs is
    component knuth_yao_single_Ngs_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    knuth_yao_single_Ngs_rom_U :  component knuth_yao_single_Ngs_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;

