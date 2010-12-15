module SphinxPort
  class Stemmer
    attr_accessor :input

    def initialize(input)
      @input = input.strip
    end

    def stem
      @input
    end
  end
end
