# daemonize

simple program that runs a shell command in background

#### use cases

it can be used to resolve a CI/CD issue with deno runtime, and gitlab runners on a vps.

```yml
stages:          # List of stages for jobs, and their order of execution
  - deploy

deploy-job:      # This job runs in the deploy stage.
  stage: deploy
  environment: production
  script:
    # Install deno
    - curl -fsSL https://deno.land/x/install/install.sh | sh
    - export DENO_INSTALL="/home/gitlab-runner-user/.deno"
    - export PATH="$DENO_INSTALL/bin:$PATH"

    # Mandatory for prod
    - export DENO_DEPLOYMENT_ID="$(git rev-parse HEAD)"

    # Test
    - deno fmt
    - deno task ok

    # Kill previous running instance (kill process "deno" that will cause process "daemonize" to terminate)
    - killall -r "deno" || true

    # Run new instance
    - ./daemonize "deno task prod"
```