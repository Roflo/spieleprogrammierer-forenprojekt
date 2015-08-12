  * Das Projekt ist C++ und nicht C. Daher gilt die Verwendung der stdlib für std::string, io-streams und Container.
  * Der C++ Teil des Projekts ist mit VC10 (Visual Studio 2010) kompatibel.
  * Konstanten werden als Konstanten definiert, nicht über #DEFINE
  * Es werden keine globalen Variablen verwendet. Falls sie notwendig sind, ist dies mit der Team-Leitung und den Verantwortlichen der Architektur abzuklären.
  * Es werden keine statischen Variablen verwendet. Falls sie notwendig sind, ist dies mit der Team-Leitung und den Verantwortlichen der Architektur abzuklären.
  * Es werden keine Singletons verwendet. Falls sie notwendig sind, ist dies mit der Team-Leitung und den Verantwortlichen der Architektur abzuklären.
  * Alle Klassen erhalten einen Kommentar über ihren Zweck mittels "///"
  * Member-Variablen sind immer private
  * Get- und Set-Methoden sind zu vermeiden. Klassen sind gekapselte, logische Gruppierungen, keine reinen Daten-Container.
  * Es gibt keine Error-Codes. Fehler werden immer durch Exceptions modelliert.
  * Exceptions enthalten eine englische Fehlerbeschreibung
  * Exceptions: throw by value, catch by const reference
  * Static-Methoden sind entweder Factories oder gehören in eine statische Utility-Klasse
  * Methoden sind niemals länger als 20 Zeilen. Längere Methoden müssen aufgesplittet werden
  * Boolsche Ausdrücke enthalten niemals mehr als 4 Operatoren
  * Verwendung von Referenzen in Parametern, sofern Pointer nicht absolut notwendig für die Operation ist
  * Kommentare nur für ein "was", niemals für "wie". Ist ein "wie" notwendig, dann Code so umschreiben, dass er selbsterklärend ist.
  * Es gelten alle Regeln bezüglich [Code Smell](http://en.wikipedia.org/wiki/Code_smell)