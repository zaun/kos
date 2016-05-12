function bigNum {
  parameter l.
  parameter c.
  parameter n.

  if n = 0 {
    print "  XXXX  " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print " XX  XX " at (c,l+2).
    print " XX  XX " at (c,l+3).
    print " XX  XX " at (c,l+4).
    print " XX  XX " at (c,l+5).
    print " XX  XX " at (c,l+6).
    print "  XXXX  " at (c,l+7).
  }
  if n = 1 {
    print "   XX   " at (c,l+0).
    print "  XXX   " at (c,l+1).
    print " XXXX   " at (c,l+2).
    print "   XX   " at (c,l+3).
    print "   XX   " at (c,l+4).
    print "   XX   " at (c,l+5).
    print "   XX   " at (c,l+6).
    print " XXXXXX " at (c,l+7).
  }
  if n = 2 {
    print "  XXXX  " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print "     XX " at (c,l+2).
    print "     XX " at (c,l+3).
    print "    XX  " at (c,l+4).
    print "   XX   " at (c,l+5).
    print "  XX    " at (c,l+6).
    print " XXXXXX " at (c,l+7).
  }
  if n = 3 {
    print "  XXXX  " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print "     XX " at (c,l+2).
    print "  XXXXX " at (c,l+3).
    print "  XXXXX " at (c,l+4).
    print "     XX " at (c,l+5).
    print " XX  XX " at (c,l+6).
    print "  XXXX  " at (c,l+7).
  }
  if n = 4 {
    print "  X   X " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print " XX  XX " at (c,l+2).
    print " XXXXXX " at (c,l+3).
    print "  XXXXX " at (c,l+4).
    print "     XX " at (c,l+5).
    print "     XX " at (c,l+6).
    print "     XX " at (c,l+7).
  }
  if n = 5 {
    print " XXXXXX " at (c,l+0).
    print " X      " at (c,l+1).
    print " XXXX   " at (c,l+2).
    print "  XXXX  " at (c,l+3).
    print "     XX " at (c,l+4).
    print "     XX " at (c,l+5).
    print " XX  XX " at (c,l+6).
    print "  XXXX  " at (c,l+7).
  }
  if n = 6 {
    print "  XXXX  " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print " XX     " at (c,l+2).
    print " XXXXX  " at (c,l+3).
    print " XXXXXX " at (c,l+4).
    print " XX  XX " at (c,l+5).
    print " XX  XX " at (c,l+6).
    print "  XXXX  " at (c,l+7).
  }
  if n = 7 {
    print " XXXXXX " at (c,l+0).
    print " XXXXXX " at (c,l+1).
    print "    XX  " at (c,l+2).
    print "    XX  " at (c,l+3).
    print "   XX   " at (c,l+4).
    print "   XX   " at (c,l+5).
    print "  XX    " at (c,l+6).
    print "  XX    " at (c,l+7).
  }
  if n = 8 {
    print "  XXXX  " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print " XX  XX " at (c,l+2).
    print " XXXXXX " at (c,l+3).
    print " XXXXXX " at (c,l+4).
    print " XX  XX " at (c,l+5).
    print " XX  XX " at (c,l+6).
    print "  XXXX  " at (c,l+7).
  }
  if n = 9 {
    print "  XXXX  " at (c,l+0).
    print " XX  XX " at (c,l+1).
    print " XX  XX " at (c,l+2).
    print " XXXXXX " at (c,l+3).
    print "  XXXXX " at (c,l+4).
    print "     XX " at (c,l+5).
    print " XX  XX " at (c,l+6).
    print "  XXXX  " at (c,l+7).
  }
}

print "loading bignum.inc".
