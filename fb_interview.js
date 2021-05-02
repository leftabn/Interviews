class Emitter {

  constructor() {
    this.eventsHandler = new Map();
  }

  subscribe(event, callback) {
    let subscription = this.eventsHandler[event];
    if (subscription) {
      subscription.callbacks.push(callback);
    }
    else {
      subscription = {
        callbacks: [callback],
        release: function() {
          while (this.callbacks.length) {
            this.callbacks.pop();
          }
        }
      }
      this.eventsHandler[event] = subscription;
    }
    return subscription;
  }

  emit(event, first_value, second_value) {
    const events = this.eventsHandler[event];
    for (let i = 0; i < events.callbacks.length; i++) {
      events.callbacks[i](first_value, second_value);
    }
  }
};

const emitter = new Emitter();

const test = function (a, b) {
  console.log(a, b);
};

const sub = emitter.subscribe("event_name", test);

emitter.emit("event_name", "first_value", "second_value");

sub.release();
