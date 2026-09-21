/// Represents a base class for Laptops.
class Laptop {
  final String name;
  final String color;

  /// Constructor for Laptop.
  /// Requires named parameters [name] and [color].
  Laptop({required this.name, required this.color}) {
    print("Laptop constructor");
    print("Name: $name");
    print("Color: $color");
  }
}

/// Represents a MacBook, inheriting from [Laptop].
class MacBook extends Laptop {
  /// Constructor for MacBook.
  /// Passes named parameters to the [Laptop] super constructor.
  MacBook({required String name, required String color})
      : super(name: name, color: color) {
    print("MacBook constructor");
  }
}

/// Main entry point for the program.
void main() {
  final macbook = MacBook(name: "MacBook Pro", color: "Silver");
  // Prevent unused variable warning
  print("Object created: $macbook");
}