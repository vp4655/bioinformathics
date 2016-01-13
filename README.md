# Bioinformatics project - Rank/Select


[![License](https://img.shields.io/packagist/l/doctrine/orm.svg)](https://img.shields.io/packagist/l/doctrine/orm.svg)

Class project for [Bioinformatics class](http://www.fer.unizg.hr/en/course/bio) on [Faculty of Electrical Engineering and Computing, University of Zagreb](http://www.fer.unizg.hr/en)


## Goal

Compressed data structures aims at representing classical data structures  in little space while keeping the functionality of the structure. In this project goal was to achive fast and accurate rank and select functions on big sequences of genomes found at [Bacteria ensamble website](http://bacteria.ensembl.org/index.html).

## Implementation

Data structures used for implementation of fast rank and select operation on big sequences are Red Black Trees with Wavelet Trees in their nodes. By choosing those two structures we can achive fast search for right subsequence of inital data O(logN) with fast rank and select operations of Wavelet tree O(logA) - where A stands for alphabet size. Project is completely done in C++.

## Usage

TODO

## Bacterias testing with memory usage and time statistics

Pull project to your local directory ( eg. your_local_path/rank_select ) open bioinformatics folder with your console and follow next steps to see results for bacterias tested.

#### Anaplasma phagocytophilium

>
>
> g++ -std=c++0x anaplasma_phagocytophilum.cpp -o anaplasma -lpsapi
> anaplasma < ./bacterias/Anaplasma_phagocytophilum.GCA_000968465.1.30.dna.toplevel.fa
>
>

#### Echericia coli

>
>
> g++ -std=c++0x echericia_coli.cpp -o echericia -lpsapi
> echericia < ./bacterias/Escherichia_coli.GCA_000967155.1.30.dna_rm.toplevel.fa
>
>

#### Salmonella enterica

>
>
> g++ -std=c++0x salmonella_enterica.cpp -o salmonella -lpsapi
> salmonella < ./bacterias/Salmonella_enterica.GCA_000783815.1.30.dna.toplevel.fa
>
>

#### Mycobacterium tuberculosis

>
>
> g++ -std=c++0x mycobacterium_tuberculosis.cpp -o tuberculosis -lpsapi
> tuberculosis < ./bacterias/Anaplasma_phagocytophilum.GCA_000968465.1.30.dna.toplevel.fa
>
>


If you wish to run programs without memory usage and time statistics, just compile .no_memory.cpp bacteria files and compile without -lpsapi.

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


