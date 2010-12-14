desc "build the orginal c++ bits of sphinx"
task :build_sphinx do
  `g++ -c cpp/*.cpp`
  `g++ -o bin/original_stemmer *.o`
end

desc "run the original stemmer"
task :run do
  system "bin/original_stemmer"
end

task :build_and_run => [:build_sphinx, :run]

task :default => [:build_and_run]

