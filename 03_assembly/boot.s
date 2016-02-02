#bu bir yorumdur ve derleyici tarafından onemsenmez

#istediginiz kadar bosluk birakabilirsiniz


.code16					#kodumuz 16 bit olacak
.intel_syntax noprefix	#intel syntaxını kullanacagiz,bizim icin kodlamada kolaylik olacak
.text                   #kodun başladığını belirtir.Gnu Assemblera(GAS) has bir koddur.Yazmalıyız
.org 0x0            	#kodun kaynaği 0x0, 0x0 kodlarin baslangic konumu olacak, kullanisli olacak


.global main			#baslangicımızın main olduğunu belirtiyoruz
main:					#ana ifade(fonksiyonumsu)
  jmp basla		#jmp ifadesi jump yani ifadeye zıplama 


.func yazdir 			#yazdırma fonksiyonu başlangıcı
yazdir:
  lodsb                   # lodsb = load string, al ye yuklemeye yapılıyor
  or     al, al           # karekterin 0 (yani son) olup olmadığını kontrol ediyoruz
  jz     yazdir_tamam 	  # eger sıfırsa sona zıpla

  mov    ah, 0xe          # 0xe ve int 10h ekrana yazı yazdırma için gereklidir
  mov    bx, 9            # bh yi 0 başlangıç konumu, ve bl özelliğini beyaz yap (9)
  int    0x10             # BIOS kesmesini(int yani interrupt) çağır.Bu kod(0x10) ekrana yazdırmak için özel bir koddur

  jmp    yazdir      	  # bir sonraki karakter için tekrar et(jmp olduğuna dikkat edin)

yazdir_tamam:
  retw                  #fonksiyondan çıkış
.endfunc



basla:
  # yükleme mesajını göster:
  lea  si, yukleme_mesaji
  call yazdir
  lea  si, merhaba_dunya_mesaji
  call yazdir


# PROGRAM VERILERI DEGISKEN OLARAK DUSUNULEBİLİR
#.asciz C de stringe(ascii) karşılık gelir 
yukleme_mesaji:          .asciz "Isletim sistemi yuklaniyor...\r\n"
merhaba_dunya_mesaji:        .asciz "Merhaba Dunya!.\r\n"

.fill (510-(.-main)), 1, 0  #  510 byte yı 0 la dolduruyoruz (OzelSayi haric)
OzelSayi:  .int 0xAA55     # BIOS un işletim sistemimizi tanıması için gerekli kod
