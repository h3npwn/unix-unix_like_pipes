# 🔧 Pipes of linux

**Pipex** is a project from the **42 curriculum** that aims to recreate the behavior of the **Unix shell pipe (`|`)** using C.  
It teaches process control, inter-process communication (IPC), and file descriptor redirection by handling **multiple commands** and their **input/output streams** manually.

---

## 🚀 Overview

The goal of this project is to implement a program that mimics this shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

And turn it into a C program execution of the form:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

The program:
1. Takes four arguments — input file, first command, second command, and output file.  
2. Creates a **pipe** between the two commands.  
3. Redirects input and output correctly using `dup2()`.  
4. Executes the commands using `execve()`.

---

## ⚙️ Example

### 🧠 Shell equivalent
```bash
< infile ls -l | grep .c > outfile
```

### 🧰 Pipex version
```bash
./pipex infile "ls -l" "grep .c" outfile
```

Both commands produce the same result.

---

## 🧩 Project Structure

```
pipex/
├── pipex.c
├── pipex.h
├── utils.c
├── Makefile
├── libft/ (optional dependency)
└── README.md
```

---

## 🧠 Key Concepts

- **Processes and PIDs**  
  Using `fork()` to create child processes.

- **Pipes and IPC**  
  Managing data flow between commands using `pipe()`.

- **File Descriptors and Duplication**  
  Redirecting input/output streams via `dup2()`.

- **Program Execution**  
  Launching programs with `execve()`.

- **Error Handling & Exit Codes**  
  Detecting invalid paths, permissions, or command errors.

---

## 🔨 Compilation

Compile using the provided Makefile:

```bash
make
```

This creates the `pipex` executable.

Or compile manually:

```bash
gcc -Wall -Wextra -Werror pipex.c utils.c -o pipex
```

---

## ▶️ Usage

### **Basic:**
```bash
./pipex infile "cmd1" "cmd2" outfile
```

### **Example:**
```bash
./pipex input.txt "grep 42" "wc -l" output.txt
```

### **Output:**
The result of `grep 42` piped into `wc -l` is written to `output.txt`.

---

## 🧰 Bonus Part (Optional)

The bonus version supports:
- **Multiple commands**:
  ```bash
  ./pipex infile "cmd1" "cmd2" "cmd3" "cmd4" outfile
  ```
- **Here-document (`here_doc`)** mode:
  ```bash
  ./pipex here_doc LIMITER cmd1 cmd2 outfile
  ```

This mimics the shell syntax:
```bash
cmd << LIMITER | cmd1 | cmd2 >> outfile
```

---

## 💡 Skills Gained

- Deep understanding of **UNIX system calls**  
- Handling **processes, file descriptors, and environment variables**  
- Implementing **pipes** and **I/O redirection** manually  
- Writing **robust error handling** for real-world command execution  

---

## 🏁 Objectives

By completing **Pipex**, you will:
- Understand how the **shell executes commands and pipes** them together  
- Master **process control and inter-process communication**  
- Improve debugging and memory management skills  

---

## 🏆 Grade
✅ Project successfully completed at **42 Network**

---

## 📜 License
This project is released under the [MIT License](LICENSE).

---

### 👨‍💻 Author
**Ahmed Bahja (h3nix)**  
📧 [h3nix.42@gmail.com](mailto:h3nix.42@gmail.com)  
🐙 [GitHub: h3nix](https://github.com/h3nix)
