# clang++ -Xpreprocessor -fopenmp -L /usr/local/opt/llvm/lib -lomp  main.cpp func1D.cpp integrate1D.cpp func2D.cpp integrate2D.cpp func3D.cpp integrate3D.cpp integrate3DAlpha.cpp alphaAnalytic.cpp perturberExtended.cpp alphaExtended.cpp -O3 -o mcint
# ./mcint

gcc  main.cpp func1D.cpp integrate1D.cpp func2D.cpp integrate2D.cpp func3D.cpp integrate3D.cpp integrate3DAlpha.cpp alphaAnalytic.cpp perturberExtended.cpp alphaExtended.cpp test1.cpp test2.cpp  -O3 -o mcint
./mcint
