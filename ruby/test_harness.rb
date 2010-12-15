require 'ruby/sphinx_port/stemmer'

module TestHarness
  def self.run(stemmed_dictionary)
    File.open(stemmed_dictionary, "r") do |f|
      all_lines = f.readlines

      num_correct_matches = all_lines.inject(0) do |total_matches, line|
        result = test_stem(*(line.split(',')))
        result ? total_matches + 1 : total_matches
      end

      percentage_correct = num_correct_matches.to_f / all_lines.length.to_f * 100
      puts "#{num_correct_matches} out of #{all_lines.length}: #{percentage_correct.to_i}%"
    end
  end

  def self.test_stem(input, expected_result)
    stemmed_result = SphinxPort::Stemmer.new(input)
    stemmed_result.stem == expected_result.strip
  end
end
