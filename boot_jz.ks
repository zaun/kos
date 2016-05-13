clearscreen.
set ship:control:pilotmainthrottle to 0.
CORE:PART:GETMODULE("kOSProcessor"):DOEVENT("Open Terminal").

set shipScript to "jz_" + ship:name + "_launch.ks".
if exists("helper.ks") {
  delete "helper.ks".
}
log "copy " + shipScript + " from 0." to "helper.ks".
log "run " + shipScript + "." to "helper.ks".

if exists("hud.inc") = false {
  copy bignum.inc from 0.
  run once bignum.inc.
  delete bignum.inc.

  copy hud.inc from 0.
  copy info.inc from 0.
  copy launch.inc from 0.
  copy orbit.inc from 0.
}

run once hud.inc.
run once info.inc.
run once launch.inc.
run once orbit.inc.

wait 1.
run helper.ks.

output(GREEN,"Program finished").
until false wait 1.
