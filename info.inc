function engineInfoStage {
  parameter stageNumber is stage:number.
  local solidMinBurnTime is 99999.
  local solidTotalThrust is 0.
  local solidCount is 0.
  local engList is list().
  list engines in engList.
  for eng in englist {
    print eng:resources:length +  "-" + eng:name.
    if eng:resources:length <> 0 and eng:stage = stageNumber {
      for r in eng:resources {
        if r:name = "solidfuel" {
          set solidCount to solidCount + 1.
          // Specific impulse
          local isp is eng:isp.
          if isp = 0 {
            // prevent div by zero
            set isp to 0.001.
          }

          // Current thrust
          local thrust is eng:thrust.
          set solidTotalThrust to solidTotalThrust + thrust.
          local mDot is thrust / (isp * 9.81).
          if mDot = 0 {
            // prevent div by zero
            set mDot to 0.001.
          }

          // Burn time
          local burnTime is (r:amount * 0.0075) / mDot.
          if burnTime < solidMinburnTime {
            set solidMinBurnTime to burnTime.
          }
        }
      }
    }
  }
  return list(solidCount, solidMinBurnTime, solidTotalThrust).
}

function engineInfoActive {
  list engines in engList.
  local curT is 0.
  local maxT is 0.
  local mdoT is 0.
  for eng in englist {
    if eng:ignition {
      set maxT to maxT + eng:availablethrust.
      set curT to curT + eng:thrust.
      if not eng:isp = 0 {
        set mdoT to mdoT + curT / eng:isp.
      }
    }
  }
  local avgISP is 0.
  if mdoT <> 0 {
    local avgISP is curT / mdoT.
  }
  return list(curT, maxT, avgISP, mdoT).
}

print "loading info.inc".
