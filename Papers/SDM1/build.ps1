latexmk -pdf -output-directory='out'
Get-ChildItem "out" -file -recurse | Where-Object {$_.extension -ne ".pdf"} | Remove-Item