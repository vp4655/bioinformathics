# Bioinformatics project - Rank/Select


[![License](https://img.shields.io/packagist/l/doctrine/orm.svg)](https://img.shields.io/packagist/l/doctrine/orm.svg)

Class project for [Bioinformatics class](http://www.fer.unizg.hr/en/course/bio) on [Faculty of Electrical Engineering and Computing, University of Zagreb](http://www.fer.unizg.hr/en)


## Goal

Compressed data structures aims at representing classical data structures  in little space while keeping the functionality of the structure. In this project goal was to achive fast and accurate rank and select functions on big sequences of genomes found at [Bacteria ensamble website](http://bacteria.ensembl.org/index.html).

## Implementation

Data structures used for implementation of fast rank and select operation on big sequences are Red Black Trees with Wavelet Trees in their nodes. By choosing those two structures we can achive fast search for right subsequence of inital data O(logN) with fast rank and select operations of Wavelet tree O(logA) - where A stands for alphabet size. Project is completely done in C++.

License
---------
The MIT License (MIT)

Copyright (c) 2016 Valentino Perović, Stjepan Livačić, Marta Poštenjak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


