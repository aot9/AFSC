<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
	<head>
		<meta http-equiv="content-type" content="application/xhtml+xml; charset=utf-8"/>
		<title>Asus F3Jp fan control on Linux</title>
		<style type="text/css">
			* { padding: 0; margin: 0; font-size: 1em; }
			img { border: 0; }
			a { color: #000033; }
			a:hover { color: #223366; }
			body { font: 14px Arial, Helvetica; padding: 30px 0; }
			small { font-size: 0.9em; }
			html, body, #container { width: 100%; height: 100%; text-align: center; }
			#content { margin: 0 auto; width: 900px; text-align: left; }
			#logo { display: block; margin: 0 auto 2em auto; width: 206px; }
			.icon { vertical-align: text-bottom; }
			h1 { font-size: 1.8em; color: #202020; }
			p { line-height: 1.5em; margin-bottom: 1em; }
			pre { padding: 10px; border: 1px solid #c7d4dd; background: #f8f8f8; margin-bottom: 1em; }
			.source_keyword { color: #000099; }
			.source_comment { color: #009900; }
			.source_literal { color: #660066; }

			.comments { padding-top: 20px; }
			.comment { padding-bottom: 30px; }
			.comment_date { display: inline; padding-right: 40px; }
			.comment_name { display: inline; font-weight: bold; }
			.comment_text { border-top: 1px solid #aaa; padding-top: 3px; line-height: 1.5em; }

			.new_comment form { padding-top: 20px; }
			.new_comment input.text { width: 300px; }
			.new_comment textarea { width: 99%; height: 200px; }
			.new_comment input.submit { width: 100px; }
		</style>
	</head>
	<body>
		<table id="container"><tbody><tr><td>
			<div id="content">
				<h1>Asus F3Jp fan control on Linux</h1>
				<p><small>Alexander Breckel, last update on 2008/09/08</small></p>

				<p>
					I'm a more or less proud owner of an Asus F3Jp notebook, running a dualboot setup with Archlinux and Windows XP.
					Unfortunately on Linux the CPU fan is constantly running and over time the fan noise became so annoying that I tried to fix the problem. Here's a summary of what I did.
				</p>

				<p><strong>
					Caution: PLEASE do not try any of this at home without being FULLY aware of the consequences.
					I'm writing this solely for your information and I cannot be held responsible for ANY damage this probably will do to your notebook, your family or your country.
				</strong></p>

				<p>
					My setup consists of an <a href="http://asus.com/products.aspx?modelmenu=2&model=1358&l1=5&l2=26&l3=316&l4=0">Asus F3Jp</a> running an up-to-date <a href="http://archlinux.com/">Archlinux 2008.06</a> with the version 2.6.26 of the Linux kernel.
					The CPU fan is constantly running; not on full speed, but still pretty loud.
					I tried to run <a href="http://www.lm-sensors.org/">lm_sensors</a> using <a href="http://wiki.archlinux.org/index.php/Lm_sensors">this manual</a>, but `sensors` only reported the following:
				</p>

<pre><strong>~$ sensors</strong>
acpitz-virtual-0
Adapter: Virtual device
temp1:       +54.0°C  (crit = +105.0°C)

coretemp-isa-0000
Adapter: ISA adapter
Core 0:      +59.0°C  (high = +100.0°C, crit = +100.0°C)

coretemp-isa-0001
Adapter: ISA adapter
Core 1:      +59.0°C  (high = +100.0°C, crit = +100.0°C)</pre>

				<p>
					No fans are detected, because <strong>/proc/acpi/fan/</strong> is empty. Normally there should be a subdirectory for each fan containing state information like RPM.
					<a href="http://tuxmobil.org/pnp_ids.html">This list</a> indicates, that an "ACPI fan" should report the PnP Device ID <strong>PNP0C0B</strong>, but <strong>/sys/bus/acpi/devices/PNP0C0B:0x</strong> does not exist.
					So the problem is, that the CPU fan is either not ACPI compliant at all or just badly configured.
					I updated the BIOS to the current <a href="http://support.asus.com/download/download.aspx?SLanguage=en-us&model=F3Jp&type=map&mapindex=0">version 209</a> without noticing any changes.
					Interestingly on Windows XP SP2 the fan can be throttled with the Software <a href="http://www.pbus-167.com/">Notebook Hardware Control</a> (NHC) using its ACPI Control System.
					So it <strong>is</strong> possible to control the fan via ACPI, but somehow something on Linux prevents this from happening.
				</p>

				<p>
					So lets take a look at how NHC manages to control the fan.
					Fortunately the relevant source code is available if you download and install the software.
					If you open up <strong>%INSTALLDIR%\acpi\ASUSTeK.cs</strong>, there is a beautiful piece of information I'll copy in here.
					Please contact me if you want this removed from here.
				</p>

<pre>8333  // Fan control for Asus F3JP
8334  // User class by Martin Nössing
8335  //
8336  // The Fan speed will be controlled by the <strong>_SB.PCI0.SBRG.EC0.WMFN</strong> register in the Embedded Controller.
8337  // WMFN is a 8 bit register. The MSB (Bit 7) control the method of fan control:
8338  //  manual = 0, automatic (default)= 1
8339  // The next 4 Bit (Bit 6 - 2) sets the <strong>fan speed</strong> (only when Bit 7 is 0):
8340  //  value 0x0 to 0x5: fan is off
8341  //  from value 0x5 to 0xF: fan speeds in ascending order
8342  //  The only problem is that a maximum fan speed set in WMFN(0xF) is not the realy maximum speed of the fan. In automatic mode,
8343  //  the fan can drive the motor more faster on higher tempertures!
[...]
8353  //<strong>****NOTE!!:IF YOU TURN YOUR FAN OFF MANUALLY, OVERHEATING MAY OCCUR.!!****</strong></pre>

				<p>
					In 2004 Alex Williamson wrote a <a href="http://www.ussg.iu.edu/hypermail/linux/kernel/0409.2/1136.html">Linux kernel patch</a> that made ACPI objects and methods accessible in /sys/firmware/acpi/namespace/ACPI, but with Linux 2.6.21 the ACPI namespace <a href="http://www.linuxhq.com/kernel/v2.6/23/Documentation/feature-removal-schedule.txt">was removed</a>.
					If your kernel version is lower than that, you could try the approach described in <a href="http://www.abclinuxu.cz/hardware/sestavy/notebooky/asus/asus-f3jc">here</a> in some weird language.
					I found no way to get raw access to ACPI without modifying the kernel, which I really want to avoid.
					But if we cannot work with ACPI, maybe we could work <i>like</i> ACPI and emulate what it would have done if we had somehow modified _SB.PCI0.SBRG.EC0.WMFN.
				</p>

				<p>
					So lets take a short look at what ACPI is and does.
					For deeper knowledge consider reading <a href="http://en.wikipedia.org/wiki/Advanced_Configuration_and_Power_Interface">Wikipedia</a> and some parts of the <a href="http://acpi.info/spec.htm">ACPI Specification</a>, especially chapter 17 on ASL.
					The <i>Advanced Configuration and Power Interface</i> provides important information about your hardware and callable methods to control it.
					Altough it is technically capable of saving the human race, it is widely used to toggle <a href="http://en.wikipedia.org/wiki/Hibernate_(OS_feature)">suspend</a> and monitor your battery status.
					The most interesting part for now is the <a href="http://www.lesswatts.org/projects/acpi/overridingDSDT.php">Differentiated System Description Table</a> (DSDT).
					Among other things it contains the definition of <strong>_SB.PCI0.SBRG.EC0.WMFN</strong>.
					The DSDT can be accessed at <strong>/proc/acpi/dsdt</strong>, but unfortunately it has to be disassembled first to be human readable.
					You probably need to install the <i>Intel ACPI Source Language Compiler</i>, which is part of the <a href="http://acpica.org/downloads/index.php">ACPICA release</a>.
					On Archlinux the package <a href="http://aur.archlinux.org/packages.php?ID=3047">community/iasl</a> provides everything you need.
				</p>

<pre><strong>~$ sudo cp /proc/acpi/dsdt dsdt</strong>
<strong>~$ iasl -d dsdt</strong>

Intel ACPI Component Architecture
AML Disassembler version 20080729 [Aug 21 2008]
Copyright (C) 2000 - 2008 Intel Corporation
Supports ACPI Specification Revision 3.0a

Loading Acpi table from file dsdt
Acpi table [DSDT] successfully installed and loaded
Pass 1 parse of [DSDT]
Pass 2 parse of [DSDT]
Parsing Deferred Opcodes (Methods/Buffers/Packages/Regions)
............................................................
Parsing completed
Disassembly completed, written to "dsdt.dsl"
</pre>

				<p>
					Now the file <strong>dsdt.dsl</strong> contains some code in ASL. I'll copy the relevant parts of my DSDT, but please keep in mind this is highly hardware- and BIOS-specific, so your version may very well differ from mine:
				</p>

<pre>
4521  Mutex (ASIO, 0x00)
[...]
5884  OperationRegion (KAID, SystemIO, 0x025C, 0x01)
5885  Field (KAID, ByteAcc, NoLock, Preserve)
5886  {
5887      AEID,   8
5888  }
5889
5890  OperationRegion (KAIC, SystemIO, 0x025D, 0x01)
5891  Field (KAIC, ByteAcc, NoLock, Preserve)
5892  {
5893      AEIC,   8
5894  }
5895
5896  Method (WEIE, 0, Serialized)
5897  {
5898      Store (0x4000, Local0)
5899      And (AEIC, 0x02, Local1)
5900      While (LAnd (LNotEqual (Local0, Zero), LEqual (Local1, 0x02)))
5901      {
5902          And (AEIC, 0x02, Local1)
5903          Decrement (Local0)
5904      }
5905  }
[...]
<strong>5982  Method (WMFN, 1, Serialized)</strong>
5983  {
5984      If (LEqual (Acquire (ASIO, 0xFFFF), 0x00))
5985      {
5986          WEIE ()
5987          Store (0x98, AEIC)
5988          WEIE ()
5989          Store (Arg0, AEID)
5990          WEIE ()
5991          Release (ASIO)
5992      }
5993  }</pre>

				<p>
					<i>AEID</i> and <i>AEIC</i> are the IO ports 0x025C and 0x025D. 'D' and 'C' sound much like Data and Control registers.
					<i>WEIE</i> is a method that waits for the seconds bit of <i>AEIC</i> to clear, probably some 'ready' status indicator.
					And <i>WMFN</i> is a method with one argument, that at first writes the byte 0x98 to the IO port <i>AEIC</i> (maybe a 'set fan speed' command) and then the argument to <i>AEID</i>.
					If you are looking for some mysterious ACPI magic ... there is none. All this code does can easily be achieved with a userspace C program like this:
				</p>

				<p><strong>
					Caution: Please do not execute this code, especially on anything else than an Asus F3Jp.
					It works for me, but probably won't work for you.
					It may even destroy your notebook as you can easily disable your CPU fan with this!
				</strong></p>

<pre><span class="source_keyword">#include</span> &lt;stdio.h> <span class="source_comment">// printf</span>
<span class="source_keyword">#include</span> &lt;stdlib.h> <span class="source_comment">// atoi</span>
<span class="source_keyword">#include</span> &lt;stdint.h> <span class="source_comment">// uint8_t, uint16_t</span>
<span class="source_keyword">#include</span> &lt;string.h> <span class="source_comment">// strcmp</span>
<span class="source_keyword">#include</span> &lt;sys/io.h> <span class="source_comment">// inb, outb</span>

<span class="source_comment">// IO ports</span>
<span class="source_keyword">const</span> uint16_t AEIC = 0x025D; <span class="source_comment">// command register</span>
<span class="source_keyword">const</span> uint16_t AEID = 0x025C; <span class="source_comment">// data register</span>

<span class="source_comment">// waits for the status bit to clear, max 0x4000 tries</span>
<span class="source_keyword">void</span> WEIE() {
	uint16_t Local0 = 0x4000;
	uint8_t Local1 = inb(AEIC) &amp; 0x02;
	<span class="source_keyword">while</span>(Local0 != 0 &amp;&amp; Local1 == 0x02) {
		Local1 = inb(AEIC) &amp; 0x02;
		Local0--;
	}
}

<span class="source_comment">// sets the fan speed</span>
<span class="source_keyword">void</span> WMFN(uint8_t Arg0) {
	WEIE();
	outb(0x98, AEIC);
	WEIE();
	outb(Arg0, AEID);
	WEIE();
}

<span class="source_keyword">int</span> main(<span class="source_keyword">int</span> argc, <span class="source_keyword">char</span> ** argv) {
	<span class="source_keyword">if</span>(argc != 2) {
		printf(<span class="source_literal">"usage: %s speed\n"</span>, argv[0]);
		printf(<span class="source_literal">"speed: `auto' or a value between 1 and 15\n"</span>);
		printf(<span class="source_literal">"keep in mind that `auto' will be even faster than 15!\n"</span>);
		<span class="source_keyword">return</span> 1;
	}

	uint8_t speed = 0xFF;
	<span class="source_keyword">if</span>(strcmp(argv[1], <span class="source_literal">"auto"</span>) == 0)
		printf(<span class="source_literal">"setting speed to 'auto'\n"</span>);
	<span class="source_keyword">else</span> {
		<span class="source_keyword">int</span> arg = atoi(argv[1]);
		<span class="source_keyword">if</span>(arg &lt; 1 || arg > 15) {
			printf(<span class="source_literal">"Error: the speed %d is not possible\n"</span>, arg);
			<span class="source_keyword">return</span> 1;
		}
		printf(<span class="source_literal">"setting speed to %d\n"</span>, arg);
		speed = (arg &lt;&lt; 3) | 0x07;
	}

	<span class="source_keyword">if</span>(ioperm(AEID, 1, 1)) {
		printf(<span class="source_literal">"Error: could not gain access to IO port AEID (0x025C)\n"</span>);
		<span class="source_keyword">return</span> 1;
	}

	<span class="source_keyword">if</span>(ioperm(AEIC, 1, 1)) {
		printf(<span class="source_literal">"Error: could not gain access to IO port AEIC (0x025D)\n"</span>);
		<span class="source_keyword">return</span> 1;
	}

	WMFN(speed);

	printf(<span class="source_literal">"done.\n"</span>);
	<span class="source_keyword">return</span> 0;
}</pre>

				<p>
					The next step could be to write a script that polls the CPU temperature and sets the fan speed appropriatly.
					I still don't know how to read the fan RPM, so a customized DSDT to allow lm_sensors to manage the fan is still far away.
				</p>

<pre><span class="source_comment">#!/bin/sh</span>

OLD_SPEED=<span class="source_literal">"0"</span>
OLD_TEMP=<span class="source_literal">"0"</span>

setSpeed () {
	<span class="source_keyword">if</span> [ <span class="source_literal">"$1"</span> != <span class="source_literal">"$OLD_SPEED"</span> ]; <span class="source_keyword">then</span>
		<span class="source_keyword">echo</span> <span class="source_literal">"new speed   $1"</span>
		OLD_SPEED=<span class="source_literal">"$1"</span>
		./fan <span class="source_literal">"$1"</span> > /dev/null
	<span class="source_keyword">fi</span>
}

<span class="source_keyword">while</span> [ 1 ]; <span class="source_keyword">do</span>
	TEMP=`cat /proc/acpi/thermal_zone/THRM/temperature | awk '{print $2}'`
	<span class="source_keyword">if</span> [ <span class="source_literal">"$TEMP"</span> != <span class="source_literal">"$OLD_TEMP"</span> ]; <span class="source_keyword">then</span>
		<span class="source_keyword">echo</span> <span class="source_literal">"temperature $TEMP C"</span>
		OLD_TEMP=<span class="source_literal">"$TEMP"</span>
	<span class="source_keyword">fi</span>

	<span class="source_keyword">if</span> [ $TEMP -gt 65 ]; <span class="source_keyword">then</span>
		setSpeed auto
	<span class="source_keyword">elif</span> [ $TEMP -gt 60 ]; <span class="source_keyword">then</span>
		setSpeed 13
	<span class="source_keyword">elif</span> [ $TEMP -gt 55 ]; <span class="source_keyword">then</span>
		setSpeed 11
	<span class="source_keyword">elif</span> [ $TEMP -gt 50 ]; <span class="source_keyword">then</span>
		setSpeed 9
	<span class="source_keyword">else</span>
		setSpeed 1
	<span class="source_keyword">fi</span>

	<span class="source_keyword">sleep</span> 2
<span class="source_keyword">done</span></pre>

				<br /><hr /><br />
				<h1>Comments</h1>
				<div class="comments">
					<div class="comment"><div class="comment_date">2013/05/19 - 08:34</div><div class="comment_name">Pierre</div><div class="comment_text">Allows a much more quiet F8Va ! Thanks ! :)<br />
<br />
here is my script using &quot;sensors&quot; :<br />
<br />
<br />
#/bin/sh<br />
/etc/setspeed 15<br />
while [ 1 ] ; do<br />
TEMP=`sensors |grep temp1 | awk '{print $2}' |sed 's/....$//'`<br />
if [ &quot;$TEMP&quot; -gt 78 ] ;<br />
then<br />
/etc/setspeed auto<br />
fi<br />
if [ &quot;$TEMP&quot; -lt 65 ] ;<br />
then<br />
/etc/setspeed 15<br />
fi<br />
sleep 4<br />
done<br />
</div></div><div class="comment"><div class="comment_date">2013/04/21 - 13:12</div><div class="comment_name">Anonymous</div><div class="comment_text">Ul30VT -&gt; Working :D</div></div><div class="comment"><div class="comment_date">2013/04/09 - 21:16</div><div class="comment_name">Anonymous</div><div class="comment_text">asus u35jc - working.</div></div><div class="comment"><div class="comment_date">2013/02/25 - 23:01</div><div class="comment_name">Thomas Oster</div><div class="comment_text">Damn! It works also on my Asus Pro 50SR Notebook. Exactly the same registers etc. Please digg deeper into that and try to make it work with lm_sensors... so you can maybe get your name into the linux-sources.</div></div><div class="comment"><div class="comment_date">2012/12/03 - 16:18</div><div class="comment_name">Tomaš</div><div class="comment_text">Hallo, <br />
ich habe ein Asus A6 (z92t) Bei diesem habe ich das gleiche Problem. Kannst Du mir bitte irgendwie helfen? Die Lüftung macht mich wahnsinnig. <br />
Wie kann ich mit Dir in Kontakt treten?<br />
<br />
Besten Gruß<br />
Tomaš</div></div><div class="comment"><div class="comment_date">2012/10/05 - 13:59</div><div class="comment_name">pulse</div><div class="comment_text">thank you very much for this article. works great for asus f8sa :)</div></div><div class="comment"><div class="comment_date">2012/05/30 - 19:57</div><div class="comment_name">GaRUi</div><div class="comment_text">Fix for reading TEMP. When the temperature is 100 it will say 10 and close the fan. Critical Problem !!!<br />
in Ubuntu 12.04 LTS use,<br />
<br />
TEMP=`cat /sys/devices/virtual/thermal/thermal_zone0/temp | awk '{print $1/1000}'`<br />
instead of<br />
TEMP=`cat /sys/devices/virtual/thermal/thermal_zone0/temp | awk '{printf(&quot;%.2s&quot;,$1)}'`<br />
<br />
</div></div><div class="comment"><div class="comment_date">2012/05/21 - 18:36</div><div class="comment_name">GaRui</div><div class="comment_text">I have changed the script a bit. Because inside my laptop there is some dust and temperature is hight at moment. So I have maxed it to 15 which is the maximum possible value for manual mode  WMFN(0xF)<br />
<br />
while [ 1 ]; do<br />
        #TEMP=`cat /proc/acpi/thermal_zone/THRM/temperature | awk '{print $2}'`<br />
        TEMP=`cat /sys/devices/virtual/thermal/thermal_zone0/temp | awk '{printf(&quot;%.2s&quot;,$1)}'`<br />
        if [ &quot;$TEMP&quot; != &quot;$OLD_TEMP&quot; ]; then<br />
                echo &quot;temperature $TEMP C&quot;<br />
                OLD_TEMP=&quot;$TEMP&quot;<br />
        fi<br />
<br />
        if [ $TEMP -gt 75 ]; then<br />
                setSpeed auto<br />
        elif [ $TEMP -gt 70 ]; then<br />
                setSpeed 15<br />
        elif [ $TEMP -gt 60 ]; then<br />
                setSpeed 13<br />
        elif [ $TEMP -gt 55 ]; then<br />
                setSpeed 11<br />
<br />
It is still much silence than auto mode. And temperature is about 74 (step 15) instead of 69 (step auto).<br />
But I need to say my CPU freq is 996MHz Instead of 1992Mhz. (I know I need to clean this fan quickly :) )<br />
It will make my days better since I will open my laptop and clean inside. <br />
<br />
<br />
Thanks again Alexander Breckel !!!</div></div><div class="comment"><div class="comment_date">2012/05/21 - 17:49</div><div class="comment_name">GaRUi</div><div class="comment_text">Script show like this below but not functioning if you do not run it with root access.<br />
(I have changed upper level to 70 for auto)<br />
 ./f3jfan-controller <br />
temperature 68 C<br />
new speed   13<br />
temperature 69 C<br />
temperature 73 C<br />
new speed   auto<br />
temperature 72 C<br />
temperature 70 C<br />
new speed   13<br />
temperature 69 C<br />
temperature 70 C<br />
<br />
&gt;  ./f3jfan 9<br />
setting speed to 9<br />
Error: could not gain access to IO port AEID (0x025C)<br />
<br />
&gt;  sudo ./f3jfan auto<br />
setting speed to 'auto'<br />
done.<br />
<br />
(Silencee!)<br />
<br />
Maybe you can set a secure bit to f3jp so everyone can run it.<br />
<br />
<br />
Big Thanks to the Alexander Breckel and Martin Nössing !!!<br />
</div></div><div class="comment"><div class="comment_date">2012/05/21 - 17:31</div><div class="comment_name">GaRui</div><div class="comment_text">It is important if someone like ME needs to do it with Ubuntu 12.04 LTS<br />
<br />
* Try &quot;/sys/firmware/acpi/tables/DSDT&quot; instead of &quot;/proc/acpi/DSDT&quot; .<br />
* TEMP=`cat /sys/devices/virtual/thermal/thermal_zone0/temp | awk '{printf(&quot;%.2s&quot;,$1)}'` <br />
  instead of TEMP=`cat /proc/acpi/thermal_zone/THRM/temperature | awk '{print $2}'`<br />
<br />
</div></div><div class="comment"><div class="comment_date">2012/01/09 - 15:27</div><div class="comment_name">Eugen</div><div class="comment_text">Hello,<br />
<br />
f3jfan is not working on my Asus F3jp and Ubuntu 11.10.<br />
<br />
I got this messages:<br />
<br />
During &quot;make&quot;:<br />
<br />
gcc -s -O2 -Wall -o f3jfan src/*.c<br />
src/main.c: In function ‘main’:<br />
src/main.c:215:8: warning: ignoring return value of ‘fread’, declared with attribute warn_unused_result [-Wunused-result]<br />
<br />
And if try to start f3jfan:<br />
<br />
X@Ente-Notebook ~/Downloads/f3jfan-0.1 $ sudo f3jfan &amp;<br />
[1] 2623<br />
X@Ente-Notebook ~/Downloads/f3jfan-0.1 $ Error: could not open `/proc/acpi/thermal_zone/THRM/temperature' for read access<br />
<br />
I couldn't solve the problem by myself.<br />
<br />
Content of folder /proc/acpi:<br />
<br />
dir ac_adapter<br />
dir battery<br />
dir button<br />
file event<br />
file wakeup<br />
<br />
But I found some Files with &quot;find /sys/ -name 'therm*'&quot; in<br />
<br />
/sys/devices/virtual/thermal/thermal_zone0<br />
<br />
There is also a file &quot;temp&quot;<br />
<br />
Any hint for solving this Prob?<br />
<br />
<br />
<br />
<br />
</div></div><div class="comment"><div class="comment_date">2011/05/20 - 19:33</div><div class="comment_name">johannes</div><div class="comment_text">ok! got it! works beautifully on asus f3jc with ubuntu 10.10! thank you! finally, no more ms!</div></div><div class="comment"><div class="comment_date">2011/04/24 - 11:34</div><div class="comment_name">johannes</div><div class="comment_text">sorry, i don't get what i need to do after running<br />
~$ sudo cp /proc/acpi/dsdt dsdt<br />
~$ iasl -d dsdt<br />
<br />
what do i do with the file dsdt.dsl?<br />
and what do i do with the code you provided?<br />
could someone please explain step by step?<br />
<br />
thank you!!!</div></div><div class="comment"><div class="comment_date">2011/01/11 - 11:58</div><div class="comment_name">dennis</div><div class="comment_text">After installing this my WLAN stopped working. Using the script on Asus F3jp.</div></div><div class="comment"><div class="comment_date">2010/09/12 - 14:43</div><div class="comment_name">sunab</div><div class="comment_text">Works perfectly on asus F3jm. Thanks. </div></div><div class="comment"><div class="comment_date">2010/09/12 - 14:43</div><div class="comment_name">sunab</div><div class="comment_text">Works perfectly on asus F3jm. Thanks. </div></div><div class="comment"><div class="comment_date">2010/07/13 - 19:40</div><div class="comment_name">dwa</div><div class="comment_text">Thanks a million! It works like a charm on a X56Va as well</div></div><div class="comment"><div class="comment_date">2010/07/04 - 20:36</div><div class="comment_name">jcolt</div><div class="comment_text">And then there was... silence... :D<br />
<br />
Works on F3JR.</div></div><div class="comment"><div class="comment_date">2010/04/04 - 12:31</div><div class="comment_name">drejk</div><div class="comment_text">my mistake, it works for X59SL :-), but the DSDT disassembly doesn't contain anything similar. weird.</div></div><div class="comment"><div class="comment_date">2010/04/04 - 12:28</div><div class="comment_name">Drejk</div><div class="comment_text">shaorang&gt; how did you make it work with x59sl? Doesn't work for me...</div></div><div class="comment"><div class="comment_date">2010/03/20 - 22:55</div><div class="comment_name">AdeBe</div><div class="comment_text">I can confirm that it works also on Asus F3F.<br />
<br />
I was trying for some time to get the same results, the only thing that I had to know was name of apropiate DSDT method.<br />
Now I'm happy :-)<br />
<br />
Great work!</div></div><div class="comment"><div class="comment_date">2010/03/20 - 22:22</div><div class="comment_name">AdeBe</div><div class="comment_text">I can confirm that it works also on Asus F3F.<br />
<br />
I was trying for some time to get the same results, the only thing that I had to know was name of apropiate DSDT method.<br />
Now I'm happy :-)<br />
<br />
Great work!</div></div><div class="comment"><div class="comment_date">2010/03/18 - 14:23</div><div class="comment_name">Paul85</div><div class="comment_text">Hi mates!<br />
I have Asus k40 and a very similar problem, so planning to use this way to fix it. Have just 2 questions:<br />
<br />
1) If someone tried it on K series?<br />
<br />
2) How to apply this code in Linux, I should compile it then and....?  (sorry for programming stupidity:))))<br />
<br />
PS. Fedora 12<br />
<br />
Thanks in advanced!!!</div></div><div class="comment"><div class="comment_date">2010/02/28 - 09:52</div><div class="comment_name">shaorang</div><div class="comment_text">Hi! Working with a X59SL series! <br />
<br />
Thanks a lot!!!</div></div><div class="comment"><div class="comment_date">2009/11/07 - 15:04</div><div class="comment_name">Grapsus</div><div class="comment_text">Working great on ASUS F3T ! My computer was so noisy while running at 55°C. Thank you very much.</div></div><div class="comment"><div class="comment_date">2009/11/07 - 04:18</div><div class="comment_name">André V.</div><div class="comment_text">Wow! I was just scared up with the silence when I executed that! I just thought for a (mili)second that the computer had shut down!<br />
It's working perfectly in my F3Jc. Thanks!</div></div><div class="comment"><div class="comment_date">2009/06/06 - 16:14</div><div class="comment_name">Alexander Breckel</div><div class="comment_text">@Vitaliy, Thanks :-)<br />
<br />
@Berion, I have to admin that after getting it to work this way I was too lazy to look further. But if anyone else wants to give it a try, I will happily post / link to the results here. Maybe the lm-sensors guys?</div></div><div class="comment"><div class="comment_date">2009/06/05 - 01:24</div><div class="comment_name">Berion</div><div class="comment_text">Hi, I just wanted to say that your program &amp; script works just fine on my Asus B50A (tried after checking the DSDT of course, where the WMFN-section is the same). Finally I can get rid of that high-pitching noise (at least with low load)! Now if it would somehow be possible to control all this with lm-sensors it would be great, but I guess you haven't gotten any further on that note, right?</div></div><div class="comment"><div class="comment_date">2009/06/03 - 08:40</div><div class="comment_name">Vitaliy</div><div class="comment_text">Alexander, I can confirm it works on Asus F3jC<br />
<br />
You saved me :) <br />
<br />
It works so nice now.</div></div><div class="comment"><div class="comment_date">2009/05/26 - 10:57</div><div class="comment_name">Samed</div><div class="comment_text">Here's the turkish translation of article: http://eventualis.org/index.php/asus-f3j-serilerinde-fan-kontrolu/<br />
</div></div><div class="comment"><div class="comment_date">2009/05/26 - 10:27</div><div class="comment_name">Alexander Breckel</div><div class="comment_text">@mebitek What happened when you compiled the C program and ran it as root? Any warnings at all?</div></div><div class="comment"><div class="comment_date">2009/05/25 - 17:13</div><div class="comment_name">mebitek</div><div class="comment_text">Hi, I have asus F3JA model, and dsdt is the same as yours. but fan speed do not seem to be changed.<br />
I'm available to discuss and help to solve this problem!<br />
<br />
thx a lot for your work,<br />
mebitek</div></div><div class="comment"><div class="comment_date">2009/05/23 - 19:03</div><div class="comment_name">Turgut Kalfaoglu</div><div class="comment_text">This is wonderful - suddenly my M51VA is TOTALLY SILENT!!<br />
Thank you!!!<br />
-ttturgut<br />
</div></div><div class="comment"><div class="comment_date">2009/05/21 - 18:58</div><div class="comment_name">Alexander Breckel</div><div class="comment_text">I've been getting some mails, so i setup a simple comment system for people to discuss this article.<br />
<br />
People told me that these scripts and programs also work on ASUS F6A and Asus B50A, altough I cannot verify this. Asus, feel free to send me Notebooks ;-)</div></div>				</div>
				<hr /><br />
				<h1>Write a comment</h1>
				<div class="new_comment">
					<form method="post" action="/knowledge/asus_f3jp_fan_control.php">
						<input type="hidden" name="action" value="new_comment" />
						<div class="form_line"><label for="comment_name">Your name:</label> <input type="text" class="text" name="name" id="comment_name" /></div>
						<div class="form_line"><label for="check">Type a '3':</label> <input type="text" class="check" name="check" id="check" /></div>
						<div class="form_line"><textarea name="text"></textarea></div>
						<div class="form_line"><input type="submit" class="submit" value="send" /></div>
					</form>
				</div>
			</div>
		</td></tr></tbody></table>
	</body>
</html>