use strict;
use warnings;

my $max_workers = 5;
my $count = 0;

for (1..$max_workers) {
  my $pid = fork;
  $count += 1;
  die "failed to fork: $!" unless defined $pid;
  # print $pid unless $pid == 0;
  next if $pid;

  print "creato figlio $$ \n";
  print "sono figlio $$, mi piace il numero: ", int rand(260), "\n";
  print "figlio $$ muore \n";
  exit;
}

my $kid;
print "padre aspetta \n";
do {
  $kid = waitpid -1, 0;
} while ($kid > 0);