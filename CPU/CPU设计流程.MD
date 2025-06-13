##芯片设计流程[比如做一个非常简单的加法电路芯片，a+b=c]
①先用Verilog或者VHDL这两种硬件专用语言,把这个加法电路描述出来
```
always @ (posedge clk) begin
    if (srst)
        c <= 0;
    else begin
        c <= a + b;
    end
end
endmodule    
```

②验证加法是不是正确，我们就要用EDA的仿真软件，比如新思的VCS和VC Formal,让a=1,b=1 看看c是不是等于2。
如果c不等于2，那么就要使用调试软件Verdi来确定问题出现在什么地方。
还需要静态和动态的分析软件，比如SpyGlass来诊断分析电路是否有一些潜在问题。


③如果上面过程没有问题，这就需要使用专门的综合工具Design Compiler生成电路，也叫网表。
然后将网表，使用IC Compiler布局布线，用PrimeTime去做时序分析，用PrimePower做功耗优化，用IC Validator做物理验证，用StarRc做寄生参数提取。等等。


④最终生成一个符号设计要求，也符号晶圆厂代工要求的GDSII文件，这个东西就被拿去做流片生产。



----------------------------------------------------------------------------------------------
以上步骤都是大厂的流程，如果小厂没有钱的话，直接使用一站式方案，用Fusion Compiler，直接将RTL -> GDSII文件。

必須補齊一點，FC不是專門給小公司做，連大公司都使用FC
好處是不用在兩個軟體之間跳來跳去
FC=DC+ICC2，但你還是需要starrc , pt ptpx等軟體做sign off
