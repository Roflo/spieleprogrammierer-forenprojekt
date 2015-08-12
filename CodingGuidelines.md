## Einrückung ##
Verwendetes Zeichen<br>
1) Leerzeichen<br>
2) 4 Zeichen<br>

3) Alles innerhalb eines Blocks<br>
4) Alles innerhalb einer Class<br>
5) Alles innerhalb eines Structs<br>
6) Alles innheralb eines Enums<br>
7) Case-Statements in Switches<br>
8) Code nach Case<br>
9) Break in Case-Block<br>

<h3>Blöcke mit { }</h3>
1) Immer auf neuer Zeile<br>
2) Einzeiligen IF/FOR/DO/WHILE immer ohne { }<br>
3) Für Konstanten auf selber Zeile, sofern nicht zu lang<br />

<h3>Umbrüche</h3>
1) Immer vor und nach "{" und "}"<br>
2) Immer vor und nach "else"<br>
3) Immer vor und nach "return", "break", "continue"<br>
4) Nach jedem ": type" bei Vererbung hintereinander<br>

<h3>Maximale Zeilenlänge</h3>
1) 120<br>

<h3>Leerzeichen</h3>
1) Vor und nach Operatoren => (x && y - a / b) || (x == 14)<br>
1.a) Nicht für "++", "--", Vorzeichen<br>
2) Nach öffnenden Klammern und vor schließenden Klammern keine Leerzeichen<br>
3) Keine nach Methoden-Namen<br>
4) Keine nach Anweisungen (if, for, do, etc) außer "case:"<br>
5) Vor und nach einer Zuweisung => x = 4<br>
6) Nach einem Komma (foo(int x, int y) - int x, y, z;)<br>
6.1) Gilt auch für Template-Parameter<br>
7) Nach einem Semikolon (for(int x=0; x<...)<br>
8) Nicht in "leeren" Arrays (int x<a href='.md'>.md</a>)<br>
9) Nicht bei Index-Zugriff (int x<a href='i.md'>i</a>)<br>
10) Nicht in eckiger Klammer (int x<a href='.md'>.md</a>)<br>

<h3>Leerzeilen</h3>
1) Vor "using"<br>
2) Zwischen "class", "struct", "enum", etc.<br>
3) Zwischen Methoden-Definitionen<br>
4) Nicht zwischen Methoden-Deklarationen<br>

<h3>Klammerung</h3>
1) Jede logische Operation wird umklammert<br>
2) Jede mathematische Operation wird umklammert, sofern nicht "Punkt vor Strich" (+-<b>/) gilt.</b>

<h2>Namen</h2>

<h3>Variablennamen</h3>

1) camelCase<br>
2) Voll ausgeschrieben, keine kryptischen Abkürzung<br>
3) Ein-Buchstaben für Schleifen-Variablen sind erlaubt<br>
4) Echte Akronyme nur den Anfangsbuchstaben groß, bzw. klein, wenn erster Buchstabe<br>

<h4>Member</h4>

1) mit Präfix "m<i>"</i>

<h4>Parameter</h4>

1) kein Präfix<br>
<br>
<h3>Methodennamen</h3>

1) Verb am Anfang<br>
2) camelCase<br>
3) Voll ausgeschrieben, keine Abkürzung<br>
<br>
<h3>Define Namen</h3>

1) Großbuchstaben mit Unterstrichen<br>
<br>
<h3>Konstanten</h3>

1) Großbuchstaben mit Unterstrichen<br>
<br>
<h3>Klassen</h3>

1) Substantiv<br>
2) großer Anfangsbuchstabe<br>
3) Kein Präfix (kein CClass!)<br>

<h3>Pfadnamen</h3>

1) Bei includes: / (foward slash)<br>
2) Bei Dateinamen: / (foward slash)<br>

<h3>Code Dateien</h3>

1) Source: <code>*</code>.cpp<br>
2) Header: <code>*</code>.hpp<br>