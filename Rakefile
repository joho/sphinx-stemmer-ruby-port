desc "build the orginal c++ bits of sphinx"
task :build_sphinx do
  `g++ -c cpp/*.cpp`
  `g++ -o bin/original_stemmer *.o`
end

desc "run the original stemmer"
task :run_sphinx do
  system "bin/original_stemmer"
end

task :build_and_run => [:build_sphinx, :run_sphinx]

desc "run the ruby version of the stemmer"
task :run_ruby do
  require 'ruby/test_harness'
  TestHarness.run("words/stemmed_dictionary.csv")
end

task :default => [:run_ruby]

