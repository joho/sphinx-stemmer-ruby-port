module SphinxPort
  class Stemmer
    attr_accessor :input

    def initialize(input)
      @input = input.strip
    end

    def stem
      return @input if @input.length <= 2


    end

  end
end
