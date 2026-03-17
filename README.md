Timer_blika_led_tlacitko_meni_led project
===========================

Účel/Zadání/Funkce
-----------------------



    1.Pomocí přerušení 16b TIMERu (TIM2, TIM3) nastavte půlperiodu blikání LED diody na přesně 400 ms.
    2.Pomocí tlačítka (reaguje na hranu) přepínejte mezi třemi různými LED. Tedy: tlačítko vybírá, která LED bliká.
    3.Zajistěte, že po přepnutí na další LED, předchozí LED zhasne. Rovněž zajistěte, že blikání bude plynulé -- tedy že rozsvícení a zhasnutí LED proběhne vždy ne při stisku tlačítka, ale v pevném časovém rámci, který je dán půlperiodou 400 ms.

Např.: Bliká LED6. Stisknu tlačítko, bliká LED5. Stisknu tlačítko, bliká LED4. Stisknu tlačítko, bliká LED6. atd. Frekvence blikání je stále stejná a je dána půlperiodou 400 ms (perioda 800 ms).




Schéma zapojení
-----------------------



Popis funkce
-----------------------

1. Timer skáče do rutiny přerušení, každých 400 ms
2. v rutině přerušení jsou 3 IFy, který každý přepíná jaká led bliká
3. Přepínání LED reaguje pouze při náběžné hraně (při stisku tlačítka)
4. V mainu se proměnná led_pointer1 nastaví na nulu, když je větší jak 2



ToDo
-----------------------



Zhodnocení
-----------------------

