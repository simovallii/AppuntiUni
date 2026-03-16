data class Product(val name: String, val category: String, val price: Double){}


fun main() {
    val products = listOf(
        Product("Laptop", "Tech", 1200.0),
        Product("Mouse", "Tech", 25.0),
        Product("Desk", "Furniture", 300.0),
        Product("Chair", "Furniture", 150.0),
        Product("Headphones", "Tech", 80.0)
    )
    //Obtain the names of the products costing more than €100.
    println("PRODOTTI CON COSTO MAGGIORE DI 100:")
    println(products.filter { it.price > 100 }.map { it.name })
    //Check whether there is at least one "Furniture" product costing less than
    //€200
    println("ESISTE ALMENO UN PRODOTTO \"FORNITURA\" CHE COSTA MENO DI 200 EURO? ")
    if (products.any { it.category == "Furniture" && it.price < 200 })
        println("SI")
        else
        println("NO")


        //Count how many products belong to the "Tech" category.
        println("PRODOTTI TECH: ")
        println(products.count { it.category == "Tech" })

        // Find the most expensive product.
        println("PRODOTTO PIU COSTOSO:")
        println(products.maxBy { it.price })

        //Group the products by category
        println("RAGGRUPPAMENTO PRODOTTI PER CATEGORIE:")
        println(products.groupBy { it.category })


    }


