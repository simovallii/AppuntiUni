package it.unipr.aerei;

	/**Si implementi in Java la classe Aereo. Ogni aereo si può trovare
	in uno dei seguenti quattro stati: in fase di decollo, in fase di crociera,
	 in fase di atterraggio, atterrato. I quattro metodi decollo, crociera, atterraggio, atterrato 
	 cambiano lo stato dell'aereo. Questi metodi devono sollevare un'eccezione (in Java sollevate 
	 l'eccezione new RuntimeException()) se non vengono chiamati nell'ordine corretto. Inoltre, 
	 il metodo nvoli restituisce il numero di voli completati da tutti gli aerei fino a quel momento
	  (hint: utilizzare un attributo di classe per tenere traccia dei voli completati).
	   Scrivere infine un main di prova che testa la classe Aereo. */

public class Aereo {

	 private static int nvoli = 0;
	 private int stato;
	 
	 public Aereo() {
		 this.stato = 0;
	 }
	 
	 public void decollo() {
		 
		 if (stato == 0) {
			 this.stato++;
		 }
		 else {
		 throw new RuntimeException("Metodo chiamato in ordine errato");
		 }
	 }
	 
	 public void crociera() {
		 
		 if (stato == 1) {
			 this.stato++;
		 }
		 else {
		 throw new RuntimeException("Metodo chiamato in ordine errato");
		 }
	 }
	 public void atterraggio() {
		 if (stato == 2) {
			 this.stato++;
		 }else {
		 throw new RuntimeException("Metodo chiamato in ordine errato");
		 }
	 }
	 public void atterrato() {
	 if (stato == 3) { 
		this.stato = 0;
		nvoli++;
		}
	 else {
	 
		 throw new RuntimeException("Metodo chiamato in ordine errato");
	 
		}
	 }
	 
	 public static int getNvoli() {
		 return nvoli;
	 }
	 
	 }

