Info<< "\nReading gravitationalProperties" << endl;
 dictionary FDict;
         IOobject FDictIO
         (
              "myg",
               mesh.time().constant(),        
               mesh,
               IOobject::MUST_READ
          );
          FDict = IOdictionary(FDictIO);
          
          autoPtr<Function1<vector>> function_ 
          (
                 Function1<vector>::New("function", FDict)
          );
          scalar indexTime = runTime.time().timeOutputValue();
          dimensionedVector g
          (
                "g",
                dimensionSet(0,1,-2,0,0,0,0),
                function_->value(indexTime)
          );    

