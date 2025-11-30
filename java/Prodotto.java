
public class Prodotto {
	
	private int codice;
	private String nome;
	private double prezzo;
	private int quantita;
	private boolean disponibilita;
	
	public Prodotto() {
		
		this(0000, " ",0, 0);
	}
	
	public Prodotto(int codice, String nome) {
		
		this(codice, nome, 0, 0);
	}
	public Prodotto(int c, String n, double prezzo, int qt) {
		
		this.codice = c;
		this.nome = n;
		this.prezzo = prezzo;
		this.quantita = qt;
		this.disponibilita = quantita > 0;
	}
	
	public int getCodice () {
		return this.codice;
	}
	
	public String getNome () {
		return this.nome;
	}
	
	public double getPrezzo () {
		return this.prezzo;
	}
	
	public int getQuantita () {
		return this.quantita;
	}
	
	public boolean getDisponibilita () {
		return this.disponibilita;
	}
	
	public void setCodice(int codice) {
		if (codice < 0)
			throw new RuntimeException("codice invalido!");
		this.codice = codice;
	}
	public void setNome(String nome) {
		
		this.nome = nome;
	}
	public void setPrezzo(double prezzo) {
		if (prezzo < 0)
			throw new RuntimeException("prezzo invalido!");
		this.prezzo = prezzo;
	}
	public void setQuantita(int qt) {
		if (qt < 0)
			throw new RuntimeException("prezzo invalido!");
		this.quantita = qt;
	}
	
	public void aggiungiQuantita(int qt) {
		
		if (quantita < 0)
			throw new RuntimeException("prezzo invalido!");
		this.quantita += qt;
		this.disponibilita = quantita > 0;
	}
	
public void aggiungiQuantita() {
		
		this.aggiungiQuantita(1);
	}

	public void rimuoviQuantita(int qt) {
		
		if(this.quantita == 0)
			throw new RuntimeException("impossibile rimuovere questa quantita");
		if(qt > this.quantita)
			throw new RuntimeException("quantita gia a zero");
		this.quantita -= qt;
		
	}
	
	public void rimuoviQuantita() {
		this.rimuoviQuantita(1);
	}
	
	public Prodotto somma(Prodotto other) {
		
		if (this.codice == other.getCodice())
		return new Prodotto(this.codice, this.nome, this.prezzo, this.quantita + other.getQuantita());
		
		throw new RuntimeException("quantita gia a zero");	
	}
	
	public boolean equals(Prodotto other) {
		
		return this.codice == other.codice;
	}
	
	public void print() {
		System.out.println(this.codice + "[" + nome + "[" + prezzo + "[" + disponibilita + "[" + quantita);
	}
public static void main(String[] args) {
	
}
}
