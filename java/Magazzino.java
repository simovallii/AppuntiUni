
public class Magazzino {

	private Prodotto[] data;
	private int size;
	private int cap;
	
	public Magazzino(int cap) {
		
		if(cap <= 0)
			throw new RuntimeException("capacita non puo essere negativa");
		this.cap = cap;
		this.data = new Prodotto[cap];
		this.size = 0;
	}
	
	public Magazzino() {
		
		this(5);
	}
	
	private void enLarge() {
		
		int Newcap = cap * 2;
		Prodotto[] newData = new Prodotto[Newcap];
		
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		
		this.data = newData;
		this.cap = Newcap;
	}
}
