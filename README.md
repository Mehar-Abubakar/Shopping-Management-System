# Shopping Management System

A simple console-based Shopping Management System built in **C++**. It simulates a basic e-commerce workflow — an admin can stock the product catalog, and customers can search products, add them to a cart, apply discount codes, and check out.

## Features

- **Admin Login** — Restricted access for adding products to the catalog (username/password protected)
- **Product Catalog** — Store product names and prices, added by the admin at runtime
- **Product Search** — Look up any product by name and view its price
- **Shopping Cart** — Add products with a chosen quantity to a cart
- **Checkout** — View a summary of cart items, total cost, and simulate payment via card number
- **Discount Codes** — Apply a discount using a code in the format `DISCOUNT<amount>` (e.g. `DISCOUNT10`)

## Tech Stack

- **Language:** C++
- **Paradigm:** Procedural, console I/O (`iostream`)

## How to Compile & Run

**Requirements:** A C++ compiler (e.g. `g++`)

```bash
# Compile
g++ ShoppingManagementSystem.cpp -o ShoppingManagementSystem

# Run
./ShoppingManagementSystem
```

## Usage

1. On launch, log in as admin (default credentials: `admin` / `password`) and add products to the catalog.
2. Once logged in, use the menu to:
   - `1` — Search for a product
   - `2` — Add a product to your cart
   - `3` — Checkout and pay
   - `4` — Apply a discount code
   - `5` — Exit

## Project Structure

```
Shopping-Management-System/
└── ShoppingManagementSystem.cpp   # Main source file
```

## Future Improvements

- Move admin credentials out of source code (currently hardcoded)
- Add input validation for prices, quantities, and card numbers
- Replace fixed-size arrays with dynamic containers (e.g. `vector`)
- Persist catalog/cart data to a file or database between runs
- Actually apply the discount to the checkout total

## License

This project is open source. Feel free to use and modify it.

