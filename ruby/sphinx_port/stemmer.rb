module SphinxPort
  class Stemmer
    attr_accessor :input

    def initialize(input)
      @input = @output = input.strip
    end

    def stem
      return @output if @output.length <= 2

      process_exceptions

      

      @output
    end

  private
    def process_exceptions
      EXCEPTIONS.each do |stemming_exception|
        
        break unless @output.length == stemming_exception.suffix.length # early abort if the exception clearly won't match the input
        break unless @output == stemming_exception.suffix # then bail out if the strings totally don't match

        @output = "#{@output[0,@output.length-stemming_exception.length_string_to_remove]}#{stemming_exception.string_to_add}"
      end
    end
  end

  StemTable = Struct.new(:length_string_to_remove, :suffix, :string_to_add)

  EXCEPTIONS = [
    StemTable.new(3, "skies",		"y"),
    StemTable.new(4, "dying",		"ie"),
    StemTable.new(4, "lying",		"ie"),
    StemTable.new(4, "tying",		"ie"),
    StemTable.new(1, "innings", nil),
    StemTable.new(1, "outings", nil),
    StemTable.new(1, "cannings",	nil),
    StemTable.new(1, "idly",	nil),
    StemTable.new(1, "gently",	nil),
    StemTable.new(1, "ugly",	"i"),
    StemTable.new(1, "early", "i"),
    StemTable.new(1, "only",	"i"),
    StemTable.new(1, "singly", nil),
    StemTable.new(0, "sky",	nil),
    StemTable.new(0, "news",		nil),
    StemTable.new(0, "howe",		nil),
    StemTable.new(0, "inning",	nil),
    StemTable.new(0, "outing",	nil),
    StemTable.new(0, "canning",	nil),
    StemTable.new(0, "proceed",	nil),
    StemTable.new(0, "exceed",	nil),
    StemTable.new(0, "succeed",	nil)
  ]

  STEP_1_TABLE = [
    StemTable.new(1, "enci",		"e" ),
    StemTable.new(1, "anci",		"e" ),
    StemTable.new(1, "abli",		"e" ),
    StemTable.new(1, "bli",		"e" ),
    StemTable.new(2, "entli",		nil),
    StemTable.new(3, "aliti",		nil),
    StemTable.new(2, "ousli",		nil),
    StemTable.new(3, "iviti",		"e" ),
    StemTable.new(5, "biliti",	"le" ),
    StemTable.new(2, "fulli",		nil),
    StemTable.new(2, "lessli",	nil),

    StemTable.new(5, "ational",	"e" ),
    StemTable.new(2, "tional",	nil),

    StemTable.new(3, "alism",		nil),

    StemTable.new(5, "ization",	"e" ),
    StemTable.new(3, "ation",		"e" ),

    StemTable.new(1, "izer",		nil),
    StemTable.new(2, "ator",		"e" ),

    StemTable.new(4, "fulness",	nil),
    StemTable.new(4, "ousness",	nil),
    StemTable.new(4, "iveness",	nil)
  ]

	STEP_2_TABLE = [
    StemTable.new(1, "enci",		"e" ),
    StemTable.new(1, "anci",		"e" ),
    StemTable.new(1, "abli",		"e" ),
    StemTable.new(1, "bli",		"e" ),
    StemTable.new(2, "entli",		nil),
    StemTable.new(3, "aliti",		nil),
    StemTable.new(2, "ousli",		nil),
    StemTable.new(3, "iviti",		"e" ),
    StemTable.new(5, "biliti",	"le" ),
    StemTable.new(2, "fulli",		nil),
    StemTable.new(2, "lessli",	nil),

    StemTable.new(5, "ational",	"e" ),
    StemTable.new(2, "tional",	nil),

    StemTable.new(3, "alism",		nil),

    StemTable.new(5, "ization",	"e" ),
    StemTable.new(3, "ation",		"e" ),

    StemTable.new(1, "izer",		nil),
    StemTable.new(2, "ator",		"e" ),

    StemTable.new(4, "fulness",	nil),
    StemTable.new(4, "ousness",	nil),
    StemTable.new(4, "iveness",	nil)
  ]

	STEP_3_TABLE = [
    StemTable.new(3, "alize",	nil),
    StemTable.new(3, "icate",	nil),
    StemTable.new(5, "ative",	nil),

    StemTable.new(3, "iciti",	nil),

    StemTable.new(2, "ical",	nil),
    StemTable.new(3, "ful",	nil),

    StemTable.new(4, "ness",	nil),
  ]

	STEP_4_TABLE = [
    StemTable.new(2, "ic",	nil),
    StemTable.new(4, "ance",	nil),
    StemTable.new(4, "ence",	nil),
    StemTable.new(4, "able",	nil),
    StemTable.new(4, "ible",	nil),
    StemTable.new(3, "ate",	nil),
    StemTable.new(3, "ive",	nil),
    StemTable.new(3, "ize ",	nil),
    StemTable.new(3, "iti",	nil),
    StemTable.new(2, "al",	nil),
    StemTable.new(3, "ism",	nil),
    StemTable.new(2, "er",	nil),
    StemTable.new(3, "ous",	nil),
    StemTable.new(5, "ement",	nil),
    StemTable.new(4, "ment",	nil),
    StemTable.new(3, "ant",	nil),
    StemTable.new(3, "ent",	nil),
  ]


end

