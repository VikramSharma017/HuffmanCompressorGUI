# HuffmanCompressorGUI

A simple GUI-based file compression and decompression application using **Huffman Coding** implemented in **C++ with Qt6**.
---
<img width="450" height="360" alt="image" src="https://github.com/user-attachments/assets/ef8cd985-ba3f-4da5-9063-69fa2dcad46e" />
<img width="450" height="360" alt="Screenshot 2025-07-10 152239" src="https://github.com/user-attachments/assets/1e64ab3b-feb9-4dcd-88c7-2db92272867b" />



---

## 📦 Features

- Compress any text-based file using Huffman coding
- Decompress previously compressed files
- Clean Qt-based GUI interface
- Displays error dialogs for failed operations
- Lightweight and beginner-friendly

---

## 🔧 Tools & Technologies

- **C++17** – Core language for logic and file handling  
- **Qt 6.9.1** – For building cross-platform GUI  
- **CMake** – Build configuration and cross-platform support  
- **MinGW (G++)** – Compiler (on Windows)  
- **Qt Creator** – Optional IDE for building and running the project

---

## 🖼️ GUI Overview

- **Browse Input** – Select the file to compress or decompress.
- **Browse Output** – Choose where to save the result.
- **Compress Button** – Start compression.
- **Decompress Button** – Start decompression.

---

## 🚀 How to Build

### ⚙ Requirements

- Qt 6.x (Tested with Qt 6.9.1)
- CMake 3.16+
- MinGW (if you're on Windows)

### 💻 Build Instructions (CLI)

```bash
git clone https://github.com/VikramSharma017/HuffmanCompressorGUI.git
cd HuffmanCompressorGUI
mkdir build && cd build
cmake ..
cmake --build .
Or, you can use Qt Creator:

Open the .pro or CMakeLists.txt file

Configure the project

Click “Build” then “Run”

📂 Folder Structure
plaintext
Copy
Edit
HuffmanCompressorGUI/
├── build/                 # Ignored in git
├── main.cpp
├── mainwindow.h / .cpp
├── mainwindow.ui
├── huffman.h / .cpp      # Huffman coding logic
├── CMakeLists.txt
├── .gitignore
└── README.md
📄 License
This project is open-source and licensed under the MIT License.

🙋‍♂️ Author
Vikram Sharma
