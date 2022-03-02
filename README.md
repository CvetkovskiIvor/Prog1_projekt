# Prog1_projekt

Zadatak programa je da pronađe sve operatore koji se nalaze u ulaznoj datoteci (C programu) te da ispiše na standardni izlaz njihov naziv, a u posebnu datoteku napiše njihovu poziciju unutar ulazne datoteke.

Problemi: ne prepoznaje kada se radi o * za definiranje pointera niti & u scanf funkciji.

Program prepoznaje operatore: +, ++, +=, -, --, -=, *, *=, !, !=, /, /=, %, %=, ~, ~=, &, &&, |, ||, ^, zarez, <, <<, <=, >, >>, >=, =, ==.
Program ne prepoznaje operatore: sizeof(), * (pokazivač na varijablu), & (adresa memorijske lokacije).
