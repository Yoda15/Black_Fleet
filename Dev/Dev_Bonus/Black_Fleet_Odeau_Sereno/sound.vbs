Set Sound = CreateObject("WMPlayer.OCX.7")
Sound.URL = "christopher-tin-sogno-di-volare-the-dream-of-flight-civilization-vi-main-theme.mp3"
Sound.Controls.play
do while Sound.currentmedia.duration = 0
wscript.sleep 100
loop
wscript.sleep (int(Sound.currentmedia.duration)+1)*1000
