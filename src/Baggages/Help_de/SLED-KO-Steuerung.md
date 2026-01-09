### KO-Steuerung

Das Verhalten der StatusLED wird durch Kommunikationsobjekte und Parameter bestimmt.

Über die Parameter kann für jeden der 4 Zustände (AUS, AN, Prio1, Prio2) das Verhalten der LED festgelegt werden.

Dabei stehen Farbe (RGB) bzw Helligkeit (einfarbig) und ein Effekt (Blinken und Pulsieren) zur Auswahl.

Um eine LED auszuschalten ist die Farbe schwarz (0x000000) bzw die Helligkeit 0% zu wählen.

Folgende Wahrheistabelle zeigt den Zusammenhang zwischen den KOs und dem LED-Bild

```
 KO Schalten | KO Prio1 | KO Prio 2 | Zustand 
-------------|----------|-----------|---------
     0       |     0    |     0     | AUS     
     1       |     0    |     0     | AN      
     x       |     1    |     0     | Prio1   
     x       |     x    |     1     | Prio2   
```


