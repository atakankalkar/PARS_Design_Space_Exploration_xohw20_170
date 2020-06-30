-- ==============================================================
-- File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2017.4
-- Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
-- 
-- ==============================================================

library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity knuth_yao_single_4jc_rom is 
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


architecture rtl of knuth_yao_single_4jc_rom is 

signal addr0_tmp : std_logic_vector(awidth-1 downto 0); 
type mem_array is array (0 to mem_size-1) of std_logic_vector (dwidth-1 downto 0); 
signal mem : mem_array := (
    0 to 1=> "0", 2 => "1", 3 => "0", 4 to 5=> "1", 6 to 9=> "0", 10 => "1", 11 to 13=> "0", 
    14 => "1", 15 to 16=> "0", 17 to 18=> "1", 19 to 22=> "0", 23 => "1", 24 to 25=> "0", 26 => "1", 
    27 to 32=> "0", 33 to 36=> "1", 37 => "0", 38 to 39=> "1", 40 => "0", 41 => "1", 42 => "0", 
    43 to 46=> "1", 47 => "0", 48 => "1", 49 => "0", 50 to 51=> "1", 52 to 54=> "0", 55 => "1", 
    56 => "0", 57 => "1", 58 => "0", 59 => "1", 60 to 61=> "0", 62 to 73=> "1", 74 => "0", 
    75 to 76=> "1", 77 to 82=> "0", 83 to 86=> "1", 87 to 88=> "0", 89 to 95=> "1", 96 to 97=> "0", 98 => "1", 
    99 to 100=> "0", 101 => "1", 102 => "0", 103 => "1", 104 to 105=> "0", 106 => "1", 107 to 108=> "0" );

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

entity knuth_yao_single_4jc is
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

architecture arch of knuth_yao_single_4jc is
    component knuth_yao_single_4jc_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    knuth_yao_single_4jc_rom_U :  component knuth_yao_single_4jc_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;

