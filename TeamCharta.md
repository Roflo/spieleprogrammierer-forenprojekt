  * Es gilt das 4-Augen-Prinzip. Ein Stück Code gilt erst dann als fertig, wenn ihn jemand anderes (der Reviewer) gesehen und beurteilt hat. Dies führt eventuell zu einem Refactoring durch den Reviewer oder eine Anweisung an den ursprünglichen Implementierer.

  * Commits in das SVN wird nur mit Code durchgeführt, welcher vorher lokal manuell getestet wurde und welcher in jedem Fall voll kompilierfähig ist, weil nicht-kompilierender Code alle anderen Entwickler komplett blockiert.

  * Alle SVN-Commits sind mit einem englischen Kommentar versehen, der die fachliche Änderung am Code kurz beschreibt.

  * Bei mehr als einem Feature pro SVN-Commit, sind mehrere Kommentare zu schreiben, zu jeder fachlichen Änderung je einer.

  * Alle Änderungen an Code werden entsprechend der CodingGuidelines und CodeConventions durchgeführt.

  * User-Stories werden in Privotal Tracker verwaltet. Jeder User startet eine Story nur dann, wenn er sie auch tatsächlich bearbeitet.

  * Der Owner einer Story darf Tasks an andere Entwickler übertragen, die Verantwortung der gesamten Story und notwendiger Koordinierung obliegt aber dem Owner.