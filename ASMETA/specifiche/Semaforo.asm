/*
 * Semaforo.asm
 * Author: Luca Ghislotti
 *
 * Piccola implementazione di una Abstract State Machine
 * che simula un semaforo.
 * 
 * Il semaforo � rappresentato tra 3 colori:
 * - VERDE: permette il passaggio delle auto (durata 20 secondi)
 * - GIALLO: avvisa dell'arrivo del rosso (durata 5 secondi)
 * - ROSSO: impedisce il passaggio (durata 10 secondi)
 * 
 * All'avvio il semaforo si trova in uno qualsiasi dei 3 colori 
 * (il colore all'avvio non � rilevanete per il corretto funzionamento
 * del semaforo).
 * 
 * L'aspetto critico � rappresentanto dalla sequenza timerale con cui
 * i colori si presentano: VERDE -> GIALLO -> ROSSO -> VERDE
 *      
 */
 
asm Semaforo
import StandardLibrary

/*
 * Dichiarazione universi e funzioni
 */
signature:

	/*
	 * Dichiarazione domini (enum)
	 */
	enum domain Colore = { VERDE | GIALLO | ROSSO } // dominio colore semaforo
	domain Seconds subsetof Integer // dominio tempo (secondi)
	
	/*
	 * Domini e funzioni controlled (leggibili e scrivibili)
	 */
	dynamic controlled stoplightColor: Colore // colore assunto dal semaforo
	dynamic controlled time: Seconds // tempo
	dynamic controlled action : String // azione implementata
	
	/*
	 * Funzioni derivate
	 */
	derived colorDuration: Colore -> Seconds // ritorna la durata massima di ciascun colore
	derived nextColor: Colore -> Colore // ritorna il successivo colore dato il colore attuale
	
/*
 * Definizione delle funzioni, delle regole, macro regole e dalla regola main.
 */
definitions:
	
	/*
	 * Funzione che ritorna la durata massima associata a ciascun colore del semaforo
	 */
	function colorDuration($colore in Colore) =
		if ($colore = VERDE) then 20
		else if ($colore = GIALLO) then 5
		else 10 endif endif
	
	/*
	 * Funzione che ritorna il successivo colore dato il colore attualmente mostrato
	 * dal semaforo
	 */
	function nextColor($coloreAttuale in Colore) = 
		if ($coloreAttuale = VERDE) then GIALLO
		else if ($coloreAttuale = GIALLO) then ROSSO
		else VERDE endif endif
	
	/*
	 * Regola per impostare il successivo stato, impostando il prossimo colore
	 * ottenuto tramite funzione nextColor() ed impostando il timer alla durata del 
	 * successivo colore tramite funzione colorDuration()
	 */
	rule r_cambioColore = 
		par
			time := colorDuration( nextColor(stoplightColor) )
			stoplightColor := nextColor(stoplightColor)
			action := "change_next_color"
		endpar
		
	/*
	 * Macro-regola che effettua il decremento del tempo ed invoca la regola
	 * di cambio colore nel caso in cui il timer associato all'attuale colore
	 * sia divenuto 0 (cambio colore necessario)
	 */
	macro rule r_decrementaUnSecondo =
		if (time > 0) then
			par
				time := time - 1
				action := "decremento_unsecondo"
			endpar
		else r_cambioColore[] 
		endif
		
	/*
	 * Macro-regola che effettua l'inizializzazione del semaforo con un colore
	 * random nel caso in cui il tempo sia impostato a -1, con il quale si indica
	 * che il semaforo � non funzionante
	 */	
	macro rule r_stoplightInitialize =
		par
			// Solo la prima volta sceglie a random uno dei tre colori dell'enum Colore
		if (time = -1) then
				choose $colore in Colore with true do
				time := colorDuration($colore)
			endif
			
			// Decrementa i secondi
			r_decrementaUnSecondo[] 
		endpar
		
	/*
	 * Definizione della regola main con la quale il semaforo viene attivato ed 
	 * inizializzato
	 */
	main rule r_Main = r_stoplightInitialize[]

	/*
	 * Definizione dei valori di inizializzazione
	 */
	default init initialize:
	
		function time = -1 // semaforo non attivo