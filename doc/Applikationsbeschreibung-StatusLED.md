<!-- DOC -->
## **Dokumentation**

<!-- DOCCONTENT
Eine vollständige Applikationsbeschreibung ist unter folgendem Link verfügbar: https://github.com/openknx/OFM-StatusLED/blob/v1/doc/Applikationsbeschreibung-StatusLED.md
DOCCONTENT -->

Dies ist ein OpenKNX-Modul zur Ansteuerung von StatusLED, wie zB LEDs auf Tastwippen oder Präsenzmeldern.

Das Repository findet man unter: https://github.com/openknx/OFM-StatusLED

<!-- DOC HelpContext="Modus" -->
#### **Modus**
Eine StatusLED kann in einem der folgenden Modus betrieben werden:
- LED-Funktion: die StatusLED wird über eine interne LED-Funktion eines OpenKNX-Moduls gesteuert. Siehe auch http://go.openknx.de/statusled
- Steuerung über KO: das Verhalten der StatusLED wird durch Kommunikatoinsobjekte und Parameter bestimmt

<!-- DOC -->
#### **LED-Funktion**
Die StatusLED wird über eine interne LED-Funktion eines OpenKNX-Moduls gesteuert. Siehe auch http://go.openknx.de/statusled

<!-- DOC -->
#### **KO-Steuerung**
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


<!-- DOC -->
#### **LED-Typ**
StatusLED können einfarbig oder mehrfarbig (RGB). Für eine korrekte Funktion der LED muss hier der zum verwendeten OpenKNX-Gerät passende Typ ausgewält werden.

Diese Einstellung ist nur sichtbar, wenn die ETS-Applikation für OpenKNX-Geräte mit unterschiedlichen LED-Typen verwendet wird.

<!-- DOC -->
#### **Erweiterte KOs**
Hier können zwei zusätzliche KOs Farbe/Helligkeit und Effekt eingeblendet werden.

"ändern den Zustand AN"  
hier werden die für den Zustand AN hinterlegten Paramter durch den jeweils gültigen Wert geändert. Eine unmittelbaren Effekt hat ein empfangender Wert auf die LED dann nur, wenn diese im Zustand AN ist.  
Somit kann hier mittels der Prio-Steuerung das über die KO definierte Verhalten wieder übersteiert werden.

"ändern direkt die LED"  
hier werden die empfangenen KOs für Farbe/Helligkeit bzw Effekt sofort an der LED wirksam, egal in welchem Zustand die LED ist.  
Ein empfangenes KO Schalten, Prio1 oder Prio2 versezt die LED jedoch wieder in den dadruch gesetzten Zustand mit den hinterlegten Parametern.
