data class Book(val title: String, val author: String, val genre : Genre)
enum class Genre(genre : String) {
    Romanzo("Romanzo"), Fantasy("Fantasy"),
    Fantascienza("Fantascienza"), Biografia("Biografia")
}
data class BookInventory(val bookList: MutableList<Book>){
    fun add(book : Book) : Unit {
        bookList.add(book)
    }
    fun removeByTitle(title: String) : Boolean{
        return bookList.removeAll{it.title == title} // consigliata da intelij

    }

    fun availableGenres() : Set<Genre>{
        val setGenre = mutableSetOf<Genre>()
        bookList.forEach {setGenre.add(it.genre) }
        return setGenre
    }

    fun countByGenre() : Map<Genre,Int>{
        val mapGenre = mutableMapOf<Genre,Int>()
        for (book in bookList){
            if(mapGenre.contains(book.genre))
                mapGenre[book.genre] = mapGenre.getValue(book.genre)+1
            else
                mapGenre.put(book.genre, 1)
        }
        return mapGenre
    }
    fun displayInventory() : Unit {
        if(bookList.size > 0){
            for (book in bookList){
                println("Titolo : ${book.title}, Autore : ${book.author}, Genere : ${book.genre}")
            }
        }
    }
}

fun main(){
    val libro1 = Book("Harry potter", "JK ROWLING", Genre.Romanzo)
    val libro2 = Book("Signore Degli Anelli", "Tolkien", Genre.Fantasy)
    val libro3 = Book("Piccole Donne", "Alcott", Genre.Romanzo)
    val scaffale = BookInventory(mutableListOf())

    scaffale.add(libro1)
    scaffale.add(libro2)
    scaffale.add(libro3)
    println(scaffale.availableGenres()) //Fantasy, Romanzo
    scaffale.displayInventory() //libro1, libro2, libro3

    scaffale.removeByTitle("Piccole Donne") //rimuove libro 3
    println(scaffale.availableGenres()) //Fantasy
    scaffale.displayInventory() // libro1, libro2

}