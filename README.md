# Nauja_Repozicija

Programa v1.1 iš jai duotų failų nuskaito duomenis apie mokinius. Jei failų neturite programa gali pati sugeneruoti atsitiktinius duomenis apie mokinius. Programa apskaičiuoja mokinių vidurkius pagal medianą arba vidurkį ir suskirsto juos į du failus "bičiuliai", mokiniai, kurių rezultatai žemiau 5 ir "galvočiai", mokiniai su aukštesniais rezultatais. Šie failai pagal vartotojo pasirinktimą gali būti saugomi dviejuose naujuose konteineriuose arba tik vienus mokinius perkeliant į naują. Veiksmai atliekami su skirtingo dydžio failais ir darbo laikai su kiekvienu failu yra išvedami. Visi skiačiavimai atliekami su vector tipo konteineriais. Laikas matuojamas kai nd skaičius lygus 10 ir galutinis rezultatas skaičiuojamas pagal vidurkį.

v1.0 naudojant struct:
100000 eiluciu failo veikimo laikas: 2.442
1000000 eiluciu failo veikimo laikas: 23.985

v1.1 naudojant class:
100000 eiluciu failo veikimo laikas: 2.112
1000000 eiluciu failo veikimo laikas: 21.177

v1.1 naudojant class, optimizacija 01:
100000 eiluciu failo veikimo laikas: 2.098
1000000 eiluciu failo veikimo laikas: 20.93

v1.1 naudojant class, optimizacija 02:
100000 eiluciu failo veikimo laikas: 2.08
1000000 eiluciu failo veikimo laikas: 21.013

v1.1 naudojant class, optimizacija 03:
100000 eiluciu failo veikimo laikas: 2.128
1000000 eiluciu failo veikimo laikas: 21.16

v1.0 naudojant struct, optimizacija 01:
100000 eiluciu failo veikimo laikas: 2.418
1000000 eiluciu failo veikimo laikas: 23.881

v1.0 naudojant struct, optimizacija 02:
100000 eiluciu failo veikimo laikas: 2.398
1000000 eiluciu failo veikimo laikas: 23.946

v1.0 naudojant struct, optimizacija 03:
100000 eiluciu failo veikimo laikas: 2.398
1000000 eiluciu failo veikimo laikas: 23.754

testavimo kompiuterio specifikacijos:
CPU - AMD Ryzen 5 2500U 
RAM - 8GB
SSD - Sandisk SD9SN8W256G1002
