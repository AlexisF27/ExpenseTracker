# Expense Tracker

ExpenseTracker is a command-line application that helps you manage your expenses. You can add, list, summarize, or delete your expense records. It stores data in JSON format for easy readability and flexibility.

## Features

- Add a new expense with a description and amount.
- List all expenses in a tabular format.
- View a summary of expenses.
- Delete an expense by ID.
- Data is saved in tasks.json for persistence.

## Requirements

- C++17 or higher: The project uses modern C++ features.
- CMake (3.10 or higher): For building the project.
- libcurl: For potential future integration with APIs.
- nlohmann/json: For handling JSON data.

## Installation

1. Clone the Repository
  ```bash
  git clone https://github.com/your-username/ExpenseTracker.git
  cd ExpenseTracker
  ```
2. Build the Project
  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ```
3. Run the Application
  ```bash
  ./ExpenseTracker
  ```

# Usage
## Comands
<table>
  <thead>
    <tr>
      <th>Command</th>
      <th>Description</th>
      <th>Example</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>add</code></td>
      <td>Adds a new expense with a description and amount.</td>
      <td><code>./ExpenseTracker add --description "Lunch" --amount 10</code></td>
    </tr>
    <tr>
      <td><code>list</code></td>
      <td>Lists all expenses in a tabular format.</td>
      <td><code>./ExpenseTracker list</code></td>
    </tr>
    <tr>
      <td><code>summary</code></td>
      <td>Displays a summary of all expenses.</td>
      <td><code>./ExpenseTracker summary</code></td>
    </tr>
    <tr>
      <td><code>delete &lt;ID&gt;</code></td>
      <td>Deletes an expense by its ID.</td>
      <td><code>./ExpenseTracker delete 1</code></td>
    </tr>
  </tbody>
</table>

