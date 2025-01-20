export function debounce(fn, wait) {
  var timeout = null
  return () => {
    if (timeout !== null) {
      clearTimeout(timeout)
    }
    timeout = setTimeout(fn, wait)
  }
}

export function getAvatarName(userName) {
  let list = userName.trim().split(/\s+/)
  let avatarName
  if (list.length > 1) {
    avatarName = `${list[0].substr(0, 1)}${list[list.length - 1].substr(0, 1)}`
  } else {
    avatarName = `${list[0].substr(0, 2)}`
  }
  return avatarName
}

export function findKey(obj, value, compare = (a, b) => a == b) {
  return Object.keys(obj).find(k => compare(obj[k], value))
}
