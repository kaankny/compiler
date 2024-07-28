<h1>K-- Compiler</h1>

<h2>Project Overview</h2>
<p>The <code>K-- Compiler</code> is a lightweight and efficient compiler for the KNN programming language, written in C++. It reads KNN source code, compiles it into an executable, and executes the compiled program.</p>

<h2>Features</h2>
<ul>
    <li><strong>Efficient Compilation:</strong> Converts KNN source code into machine code quickly and efficiently.</li>
    <li><strong>Arithmetic Operations:</strong> Supports basic arithmetic operations such as addition, subtraction, multiplication, and division.</li>
    <li><strong>Simple Syntax:</strong> Easy-to-understand syntax for quick learning and implementation.</li>
</ul>

<h2>Getting Started</h2>
<p>To start using the KNN Compiler, follow these steps:</p>

<ol>
    <li>Compile the K-- Compiler source code:</li>
    <pre><code>g++ -o k.exe knn_compiler.cpp</code></pre>
    <li>Create your KNN source code file using a text editor and save it with the <code>.knn</code> extension. For example, <code>code.knn</code>.</li>
    <li>Run the compiler to compile your KNN source code:</li>
    <pre><code>./k.exe code.knn</code></pre>
    <li>If the compilation is successful, an executable named <code>a.exe</code> will be generated.</li>
    <li>Run the generated executable to see the output:</li>
    <pre><code>./a.exe</code></pre>
</ol>

<h2>Example Usage</h2>
<p>Here is an example demonstrating the compilation and execution process:</p>

<pre><code>$ ls
code.knn
k.exe

$ cat code.knn
print 12 * 3;
print 18 - 2 * 4;
print 1 + 2 + 9 - 5 / 2 + 3 * 5;

$ ./k.exe code.knn
Compile finished!

$ ls
a.exe
code.knn
k.exe

$ ./a.exe
36
10
24.5
</code></pre>

<h2>KNN Source Code Example</h2>
<p>An example of a simple KNN source code file:</p>
<pre><code>print 12 * 3;
print 18 - 2 * 4;
print 1 + 2 + 9 - 5 / 2 + 3 * 5;
</code></pre>

<h2>Conclusion</h2>
<p>The KNN Compiler is a powerful tool for compiling and executing KNN code efficiently. Its simple syntax and quick compilation make it an excellent choice for developers looking to implement arithmetic operations in their programs.</p>
